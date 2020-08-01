#ifndef _item_h_
#define _item_h_

#define EMPTY 0
#define GRASS 1
#define SAND 2
#define STONE 3
#define BRICK 4
#define WOOD 5
#define STONE 6
#define DIRT 7
#define PLANK 8
#define SNOW 9
#define GLASS 10
#define COBBLE 11
#define LIGHT_STONE 12
#define DARK_STONE 13
#define CHEST 14
#define LEAVES 15
#define CLOUD 16
#define TALL_GRASS 17
#define YELLOW_FLOWER 18
#define RED_FLOWER 19
#define PURPLE_FLOWER 20
#define SUN_FLOWER 21
#define WHITE_FLOWER 22
#define BLUE_FLOWER 23
#define GLOWSTONE 24
#define TNT 25
#define TORCH 26
#define SOUL_TORCH 27
#define DIAMOND_ORE 28
#define GOLD_ORE 29
#define EMERALD_ORE 30
#define PRESENT 31
#define CRAFTING_TABLE 32
#define FLAME_FLOWER 33
#define ICE 34
#define ICE_WITH_SNOW 35
#define COAL_ORE 36
#define COAL 37
#define OBSIDIAN 38
#define LAPIS_LAZULI_ORE 39
#define REDSTONE_ORE 40
#define IRON_ORE 41
#define MAGMA_BLOCK 42
#define GRANITE 43
#define ANDESITE 44
#define DIORITE 45
#define WITHERED_MAGMA 46
#define MELON 47
#define GRAVEL 48
#define SNOW_BLOCK 49
#define WITHER_ROSE 50
#define CACTUS 51
#define LIGHT_BROWN_TERRACOTTA 52
#define ORANGE_TERRACOTTA 53
#define GRAY_TERRACOTTA 54
#define LIGHT_GRAY_TERRACOTTA 55
#define RED_TERRACOTTA 56
#define YELLOW_TERRACOTTA 57
#define DEAD_BUSH 58
#define BROWN_TERRACOTTA 59
#define WITHERED_GRASS 60
#define MYCELIUM 61
#define RED_MUSHROOM 62
#define GOLD_BLOCK 63

extern const int items[];
extern const int item_count;
extern const int blocks[256][6];
extern const int plants[256];

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
