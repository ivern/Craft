#include "item.h"
#include "util.h"

thing_t things[MAX_ITEM_COUNT];
int thing_count;

void
simple_block(thing_type_t id, int image)
{
    things[id].id = id;
    things[id].type = BLOCK_THING;
    things[id].attributes.block.left = image;
    things[id].attributes.block.right = image;
    things[id].attributes.block.top = image;
    things[id].attributes.block.bottom = image;
    things[id].attributes.block.front = image;
    things[id].attributes.block.back = image;

    ++thing_count;
}

void
block(thing_type_t id, int left, int right, int top, int bottom, int front, int back)
{
    things[id].id = id;
    things[id].type = BLOCK_THING;
    things[id].attributes.block.left = left;
    things[id].attributes.block.right = right;
    things[id].attributes.block.top = top;
    things[id].attributes.block.bottom = bottom;
    things[id].attributes.block.front = front;
    things[id].attributes.block.back = back;

    ++thing_count;
}

void
plant(thing_type_t id, int image) {
    things[id].id = id;
    things[id].type = PLANT_THING;
    things[id].attributes.plant.image = image;

    ++thing_count;
}

void
torch(thing_type_t id, int image) {
    things[id].id = id;
    things[id].type = PLANT_THING;
    things[id].attributes.plant.image = image;

    ++thing_count;
}

void
item_initialize(void) {
    thing_count = 0;

    block(GRASS, 16, 16, 32, 0, 16, 16);
    simple_block(SAND, 1);
    simple_block(STONE_BRICKS, 2);
    simple_block(BRICK, 3);
    block(WOOD, 20, 20, 36, 4, 20, 20);
    simple_block(STONE, 5);
    simple_block(DIRT, 6);
    simple_block(PLANK, 7);
    block(SNOW, 24, 24, 40, 8, 24, 24);
    simple_block(GLASS, 9);
    simple_block(COBBLE, 10);
    simple_block(LIGHT_STONE, 11);
    simple_block(DARK_STONE, 12);
    block(CHEST, 61, 61, 45, 45, 77, 61);
    simple_block(LEAVES, 14);
    simple_block(CLOUD, 15);
    plant(TALL_GRASS, 48);
    plant(YELLOW_FLOWER, 49);
    plant(RED_FLOWER, 50);
    plant(PURPLE_FLOWER, 51);
    plant(SUN_FLOWER, 52);
    plant(WHITE_FLOWER, 53);
    plant(BLUE_FLOWER, 54);
    simple_block(GLOWSTONE, 55);
    block(TNT, 56, 56, 104, 88, 72, 72);
    torch(TORCH, 57);
    torch(SOUL_TORCH, 73);
    simple_block(DIAMOND_ORE, 26);
    simple_block(GOLD_ORE, 27);
    simple_block(EMERALD_ORE, 28);
    block(PRESENT, 58, 58, 74, 74, 58, 58);
    block(CRAFTING_TABLE, 59, 59, 75, 43, 42, 42);
    plant(FLAME_FLOWER, 70);
    simple_block(ICE, 92);
    block(ICE_WITH_SNOW, 60, 60, 76, 44, 60, 60);
    simple_block(COAL_ORE, 31);
    simple_block(COAL, 63);
    simple_block(OBSIDIAN, 47);
    simple_block(LAPIS_LAZULI_ORE, 29);
    simple_block(REDSTONE_ORE, 30);
    simple_block(IRON_ORE, 46);
    simple_block(MAGMA_BLOCK, 62);
    simple_block(GRANITE, 78);
    simple_block(ANDESITE, 79);
    simple_block(DIORITE, 95);
    simple_block(WITHERED_MAGMA, 93);
    block(MELON, 94, 94, 110, 126, 94, 94);
    simple_block(GRAVEL, 111);
    simple_block(SNOW_BLOCK, 109);
    plant(WITHER_ROSE, 125);
    block(CACTUS, 127, 127, 143, 142, 127, 127);
    simple_block(LIGHT_BROWN_TERRACOTTA, 91);
    simple_block(ORANGE_TERRACOTTA, 90);
    simple_block(GRAY_TERRACOTTA, 89);
    simple_block(LIGHT_GRAY_TERRACOTTA, 105);
    simple_block(RED_TERRACOTTA, 106);
    simple_block(YELLOW_TERRACOTTA, 107);
    plant(DEAD_BUSH, 25);
    simple_block(BROWN_TERRACOTTA, 108);
    block(WITHERED_GRASS, 87, 87, 103, 71, 87, 87);
    block(MYCELIUM, 85, 85, 101, 69, 85, 85);
    plant(RED_MUSHROOM, 120);
    simple_block(DIAMOND_BLOCK, 124);
    simple_block(BEDROCK, 123);
    block(SNOWY_LEAVES, 35, 35, 34, 36, 35, 35);
    block(BLAST_FURNACE, 122, 122, 137, 137, 121, 122);
}

int is_plant(int w) {
    return things[w].type == PLANT_THING;
}

int is_obstacle(int w) {
    w = ABS(w);
    if (is_plant(w)) {
        return 0;
    }
    switch (w) {
        case EMPTY:
        case CLOUD:
            return 0;
        default:
            return 1;
    }
}

int is_transparent(int w) {
    if (w == EMPTY) {
        return 1;
    }
    w = ABS(w);
    if (is_plant(w)) {
        return 1;
    }
    switch (w) {
        case EMPTY:
        case GLASS:
        case LEAVES:
            return 1;
        default:
            return 0;
    }
}

int is_destructable(int w) {
    switch (w) {
        case EMPTY:
        case CLOUD:
            return 0;
        default:
            return 1;
    }
}

int is_light(int w) {
    switch (w) {
        case GLOWSTONE:
        case TORCH:
        case SOUL_TORCH:
            return 1;
        default:
            return 0;
    }
}

int is_explosive(int w) {
    switch (w) {
        case TNT:
            return 5;
        default:
            return 0;
    }
}

int is_gravity_affected(int w) {
    switch (w) {
        case SAND:
        case GRAVEL:
        case SNOW_BLOCK:
            return 1;
        default:
            return 0;
    }
}
