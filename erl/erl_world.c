// gcc -std=c99 -O3 -fPIC -I/usr/local/Cellar/erlang/23.0.3/lib/erlang/usr/include -dynamiclib -undefined dynamic_lookup -o world.so -I src -I deps/noise deps/noise/noise.c src/erl_world.c

#include <erl_nif.h>
#include "config.h"
#include "noise.h"

static void world_map_put(ErlNifEnv *env, ERL_NIF_TERM *map, int x, int y, int z, int w);

static ERL_NIF_TERM
noise_seed(ErlNifEnv *env, int _argc, const ERL_NIF_TERM argv[]) {
    unsigned int x;

    enif_get_uint(env, argv[0], &x);

    seed(x);

    return enif_make_uint(env, x);
}

static ERL_NIF_TERM
create_world(ErlNifEnv *env, int _argc, const ERL_NIF_TERM argv[]) {
    int p;
    int q;

    enif_get_int(env, argv[0], &p);
    enif_get_int(env, argv[1], &q);

    ERL_NIF_TERM map = enif_make_new_map(env);

    int pad = 1;
    for (int dx = -pad; dx < CHUNK_SIZE + pad; dx++) {
        for (int dz = -pad; dz < CHUNK_SIZE + pad; dz++) {
            int flag = 1;
            if (dx < 0 || dz < 0 || dx >= CHUNK_SIZE || dz >= CHUNK_SIZE) {
                flag = -1;
            }
            int x = p * CHUNK_SIZE + dx;
            int z = q * CHUNK_SIZE + dz;
            float f = simplex2(x * 0.01, z * 0.01, 4, 0.5, 2);
            float g = simplex2(-x * 0.01, -z * 0.01, 2, 0.9, 2);
            int mh = g * 32 + 16;
            int h = f * mh;
            int w = 1;
            int t = 12;
            if (h <= t) {
                h = t;
                w = 2;
            }
            // sand and grass terrain
            for (int y = 0; y < h; y++) {
                world_map_put(env, &map, x, y, z, w * flag);
            }
            if (w == 1) {
                if (SHOW_PLANTS) {
                    // grass
                    if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.6) {
                        world_map_put(env, &map, x, h, z, 17 * flag);
                    }
                    // flowers
                    if (simplex2(x * 0.05, -z * 0.05, 4, 0.8, 2) > 0.7) {
                        int w = 18 + simplex2(x * 0.1, z * 0.1, 4, 0.8, 2) * 7;
                        world_map_put(env, &map, x, h, z, w * flag);
                    }
                }
                // trees
                int ok = SHOW_TREES;
                if (dx - 4 < 0 || dz - 4 < 0 ||
                    dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE) {
                    ok = 0;
                }
                if (ok && simplex2(x, z, 6, 0.5, 2) > 0.84) {
                    for (int y = h + 3; y < h + 8; y++) {
                        for (int ox = -3; ox <= 3; ox++) {
                            for (int oz = -3; oz <= 3; oz++) {
                                int d = (ox * ox) + (oz * oz) +
                                        (y - (h + 4)) * (y - (h + 4));
                                if (d < 11) {
                                    world_map_put(env, &map, x + ox, y, z + oz, 15);
                                }
                            }
                        }
                    }
                    for (int y = h; y < h + 7; y++) {
                        world_map_put(env, &map, x, y, z, 5);
                    }
                }
            }
            // clouds
            if (SHOW_CLOUDS) {
                for (int y = 64; y < 72; y++) {
                    if (simplex3(
                            x * 0.01, y * 0.1, z * 0.01, 8, 0.5, 2) > 0.75) {
                        world_map_put(env, &map, x, y, z, 16 * flag);
                    }
                }
            }
        }
    }

    return map;
}

static void
world_map_put(ErlNifEnv *env, ERL_NIF_TERM *map, int x, int y, int z, int w) {
    ERL_NIF_TERM key = enif_make_tuple3(env, enif_make_int(env, x), enif_make_int(env, y), enif_make_int(env, z));
    ERL_NIF_TERM value = enif_make_int(env, w);

    enif_make_map_put(env, *map, key, value, map);
}

static ErlNifFunc nif_funcs[] = {
        // {erl_function_name, erl_function_arity, c_function}
        {"create_world", 2, create_world},
        {"seed", 1, noise_seed}
};

ERL_NIF_INIT(Elixir.CraftServer.CreateWorld, nif_funcs, NULL, NULL, NULL, NULL)
