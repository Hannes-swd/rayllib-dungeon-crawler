#include "DrawMap.h"
#include "LoadTexture.h"

void DrawMap(const Map& map, int tileSize) {
    for (int y = 0; y < map.height; y++) {
        for (int x = 0; x < map.width; x++) {
            TileType t = map.tiles[y * map.width + x];

            switch (t) {
            case TILE_Boden:
                DrawTexture("Boden", x * tileSize, y * tileSize, tileSize, tileSize);
                break;
            case TILE_WATER:
                DrawTexture("Wasser", x * tileSize, y * tileSize, tileSize, tileSize);
                break;
            case TILE_LAVA:
                DrawTexture("Lava", x * tileSize, y * tileSize, tileSize, tileSize);
                break;
            case TILE_WALL:
                DrawTexture("Wand", x * tileSize, y * tileSize, tileSize, tileSize);
                break;
            default:
                break;
            }
        }
    }
}
