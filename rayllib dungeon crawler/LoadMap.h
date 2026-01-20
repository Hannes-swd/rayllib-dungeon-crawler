#pragma once
#include "raylib.h"

enum TileType {
    TILE_EMPTY,
    TILE_Boden,
    TILE_WATER,
    TILE_LAVA,
    TILE_Wand,
    TILE_Tür
};

struct Map {
    int width;
    int height;
    TileType* tiles;
};

Map LoadMapFromImage(const char* filename);

void UnloadMap(Map& map);
