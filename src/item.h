#ifndef _item_h_
#define _item_h_

#include "config.h"

typedef enum {
    EMPTY = 0,
    GRASS = 1,
    SAND = 2,
    STONE_BRICKS = 3,
    BRICK = 4,
    WOOD = 5,
    STONE = 6,
    DIRT = 7,
    PLANK = 8,
    SNOW = 9,
    GLASS = 10,
    COBBLE = 11,
    LIGHT_STONE = 12,
    DARK_STONE = 13,
    CHEST = 14,
    LEAVES = 15,
    CLOUD = 16,
    TALL_GRASS = 17,
    YELLOW_FLOWER = 18,
    RED_FLOWER = 19,
    PURPLE_FLOWER = 20,
    SUN_FLOWER = 21,
    WHITE_FLOWER = 22,
    BLUE_FLOWER = 23,
    GLOWSTONE = 24,
    TNT = 25,
    TORCH = 26,
    SOUL_TORCH = 27,
    DIAMOND_ORE = 28,
    GOLD_ORE = 29,
    EMERALD_ORE = 30,
    PRESENT = 31,
    CRAFTING_TABLE = 32,
    FLAME_FLOWER = 33,
    ICE = 34,
    ICE_WITH_SNOW = 35,
    COAL_ORE = 36,
    COAL = 37,
    OBSIDIAN = 38,
    LAPIS_LAZULI_ORE = 39,
    REDSTONE_ORE = 40,
    IRON_ORE = 41,
    MAGMA_BLOCK = 42,
    GRANITE = 43,
    ANDESITE = 44,
    DIORITE = 45,
    WITHERED_MAGMA = 46,
    MELON = 47,
    GRAVEL = 48,
    SNOW_BLOCK = 49,
    WITHERED_ROSE = 50,
    CACTUS = 51,
    LIGHT_BROWN_TERRACOTTA = 52,
    ORANGE_TERRACOTTA = 53,
    GRAY_TERRACOTTA = 54,
    LIGHT_GRAY_TERRACOTTA = 55,
    RED_TERRACOTTA = 56,
    YELLOW_TERRACOTTA = 57,
    DEAD_BUSH = 58,
    BROWN_TERRACOTTA = 59,
    WITHERED_GRASS = 60,
    MYCELIUM = 61,
    RED_MUSHROOM = 62,
    GOLD_BLOCK = 63,
} thing_type_t;

typedef struct {
    thing_type_t id;

    enum {
        BLOCK_THING = 0,
        PLANT_THING = 1
    } type;

    union {
        struct {
            int left;
            int right;
            int top;
            int bottom;
            int front;
            int back;
        } block;

        struct {
            int image;
        } plant;
    } attributes;
} thing_t;

extern thing_t things[MAX_ITEM_COUNT];
extern int thing_count;

void item_initialize();

int is_plant(int w);
int is_obstacle(int w);
int is_transparent(int w);
int is_destructable(int w);

/* Indicates whether the specified item is a light source by default. */
int is_light(int w);

/* Returns the blast radius if the specified item is explosive, or zero otherwise. */
int is_explosive(int w);

/* Indicates whether the specified item is affected by gravity (falls if unsupported). */
int is_gravity_affected(int w);

#endif
