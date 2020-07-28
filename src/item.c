#include "item.h"
#include "util.h"

const int items[] = {
    // items the user can build
    GRASS,
    SAND,
    STONE,
    BRICK,
    WOOD,
    CEMENT,
    DIRT,
    PLANK,
    SNOW,
    GLASS,
    COBBLE,
    LIGHT_STONE,
    DARK_STONE,
    CHEST,
    LEAVES,
    TALL_GRASS,
    YELLOW_FLOWER,
    RED_FLOWER,
    PURPLE_FLOWER,
    SUN_FLOWER,
    WHITE_FLOWER,
    BLUE_FLOWER,
    GLOWSTONE,
    TNT,
    TORCH,
    BLUE_TORCH,
    DIAMOND_ORE,
    GOLD_ORE,
    EMERALD_ORE,
    PRESENT,
    CRAFTING_TABLE,
    FLAME_FLOWER,
    ICE,
    ICE_WITH_SNOW,
    COAL_ORE,
    COAL,
    OBSIDIAN,
    LAPIS_LAZULI_ORE,
    REDSTONE_ORE,
    IRON_ORE,
    MAGMA_BLOCK,
    GRANITE,
    ANDESITE,
    DIORITE,
    COLOR_14,
    COLOR_15,
    COLOR_16,
    COLOR_17,
    COLOR_18,
    COLOR_19,
    COLOR_20,
    COLOR_21,
    COLOR_22,
    COLOR_23,
    COLOR_24,
    COLOR_25,
    COLOR_26,
    COLOR_27,
    COLOR_28,
    COLOR_29,
    COLOR_30,
    COLOR_31
};

const int item_count = sizeof(items) / sizeof(int);

const int blocks[256][6] = {
    // w => (left, right, top, bottom, front, back) tiles
    {0, 0, 0, 0, 0, 0}, // 0 - empty
    {16, 16, 32, 0, 16, 16}, // 1 - grass
    {1, 1, 1, 1, 1, 1}, // 2 - sand
    {2, 2, 2, 2, 2, 2}, // 3 - stone
    {3, 3, 3, 3, 3, 3}, // 4 - brick
    {20, 20, 36, 4, 20, 20}, // 5 - wood
    {5, 5, 5, 5, 5, 5}, // 6 - cement
    {6, 6, 6, 6, 6, 6}, // 7 - dirt
    {7, 7, 7, 7, 7, 7}, // 8 - plank
    {24, 24, 40, 8, 24, 24}, // 9 - snow
    {9, 9, 9, 9, 9, 9}, // 10 - glass
    {10, 10, 10, 10, 10, 10}, // 11 - cobble
    {11, 11, 11, 11, 11, 11}, // 12 - light stone
    {12, 12, 12, 12, 12, 12}, // 13 - dark stone
    {61, 61, 45, 45, 77, 61}, // 14 - chest
    {14, 14, 14, 14, 14, 14}, // 15 - leaves
    {15, 15, 15, 15, 15, 15}, // 16 - cloud
    {0, 0, 0, 0, 0, 0}, // 17
    {0, 0, 0, 0, 0, 0}, // 18
    {0, 0, 0, 0, 0, 0}, // 19
    {0, 0, 0, 0, 0, 0}, // 20
    {0, 0, 0, 0, 0, 0}, // 21
    {0, 0, 0, 0, 0, 0}, // 22
    {0, 0, 0, 0, 0, 0}, // 23
    {55, 55, 55, 55, 55, 55}, // 24 - glowstone
    {56, 56, 104, 88, 72, 72}, // 25 - tnt
    {0, 0, 0, 0, 0, 0}, // 26 - torch
    {0, 0, 0, 0, 0, 0}, // 27 - blue torch
    {26, 26, 26, 26, 26, 26}, // 28 - diamond ore
    {27, 27, 27, 27, 27, 27}, // 29 - gold ore
    {28, 28, 28, 28, 28, 28}, // 30 - emerald ore
    {58, 58, 74, 74, 58, 58}, // 31 - present
    {59, 59, 75, 43, 42, 42}, // 32 - crafting table
    {0, 0, 0, 0, 0, 0}, // 33 - flame flower
    {92, 92, 92, 92, 92, 92}, // 34 - ice
    {60, 60, 76, 44, 60, 60}, // 35 - ice with snow
    {31, 31, 31, 31, 31, 31}, // 36 - coal ore
    {63, 63, 63, 63, 63, 63}, // 37 - coal
    {47, 47, 47, 47, 47, 47}, // 38 - obsidian
    {29, 29, 29, 29, 29, 29}, // 39 - lapis lazuli ore
    {30, 30, 30, 30, 30, 30}, // 40 - redstone ore
    {46, 46, 46, 46, 46, 46}, // 41 - iron ore
    {62, 62, 62, 62, 62, 62}, // 42 - magma block
    {78, 78, 78, 78, 78, 78}, // 43 - granite
    {79, 79, 79, 79, 79, 79}, // 44 - andesite
    {95, 95, 95, 95, 95, 95}, // 45 - diorite
    {190, 190, 190, 190, 190, 190}, // 46 -
    {191, 191, 191, 191, 191, 191}, // 47
    {192, 192, 192, 192, 192, 192}, // 48
    {193, 193, 193, 193, 193, 193}, // 49
    {194, 194, 194, 194, 194, 194}, // 50
    {195, 195, 195, 195, 195, 195}, // 51
    {196, 196, 196, 196, 196, 196}, // 52
    {197, 197, 197, 197, 197, 197}, // 53
    {198, 198, 198, 198, 198, 198}, // 54
    {199, 199, 199, 199, 199, 199}, // 55
    {200, 200, 200, 200, 200, 200}, // 56
    {201, 201, 201, 201, 201, 201}, // 57
    {202, 202, 202, 202, 202, 202}, // 58
    {203, 203, 203, 203, 203, 203}, // 59
    {204, 204, 204, 204, 204, 204}, // 60
    {205, 205, 205, 205, 205, 205}, // 61
    {206, 206, 206, 206, 206, 206}, // 62
    {207, 207, 207, 207, 207, 207}, // 63
};

const int plants[256] = {
    // w => tile
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0 - 16
    48, // 17 - tall grass
    49, // 18 - yellow flower
    50, // 19 - red flower
    51, // 20 - purple flower
    52, // 21 - sun flower
    53, // 22 - white flower
    54, // 23 - blue flower
    0, 0, // 24 - 25
    57, // 26 - torch
    73, // 27 - blue torch
    0, 0, 0, 0, 0, // 28 - 32
    70, // 33 - flame flower
};

int is_plant(int w) {
    switch (w) {
        case TALL_GRASS:
        case YELLOW_FLOWER:
        case RED_FLOWER:
        case PURPLE_FLOWER:
        case SUN_FLOWER:
        case WHITE_FLOWER:
        case BLUE_FLOWER:
        case FLAME_FLOWER:
        // TODO hacky way to render torches, fix it nicely
        case TORCH:
        case BLUE_TORCH:
            return 1;
        default:
            return 0;
    }
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
        case BLUE_TORCH:
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
            return 1;
        default:
            return 0;
    }
}
