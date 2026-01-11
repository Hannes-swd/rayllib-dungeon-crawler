#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include <vector>
#include <algorithm>


Map LoadMapFromImage(const char* filename) {
    Image img = LoadImage(filename);
    Color* pixels = LoadImageColors(img);

    Map map;
    map.width = img.width;
    map.height = img.height;
    map.tiles = (TileType*)malloc(sizeof(TileType) * img.width * img.height);

    if (map.tiles == nullptr) {
        TraceLog(LOG_ERROR, "Failed to allocate memory for map tiles!");
        UnloadImageColors(pixels);
        UnloadImage(img);
        return map;
    }
    Kisten.clear();
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            Color c = pixels[y * img.width + x];
            int index = y * img.width + x;

            unsigned int color = (c.r << 16) | (c.g << 8) | c.b;

            switch (color) {
            case 0x0000FF: // Blau  Wasser
                map.tiles[index] = TILE_WATER;
                break;
            case 0x808080: // Grau  Boden
                map.tiles[index] = TILE_Boden;
                break;
            case 0xFF8000: // Orange  Lava
                map.tiles[index] = TILE_LAVA;
                break;
            case 0x000000: // Schwarz  Wand
                map.tiles[index] = TILE_Wand;
                break;
            case 0xFFFFFF: // Weiß Leer
                map.tiles[index] = TILE_EMPTY;
                break;
                //spawnporint
            case 0x00FF00:
                map.tiles[index] = TILE_Boden;
                PlayerPosition.x = (float)x;
                PlayerPosition.y = (float)y;
				PlayerSpawn = { (float)x, (float)y };
                break;
                //mob spawn
            case 0xF200FF:
                map.tiles[index] = TILE_Boden;
                MobSpawner.push_back(Vector2{ (float)x, (float)y});
                break;
                //kisten 
            case 0xff0000:
                map.tiles[index] = TILE_Boden;
                Kisten.push_back(Vector2{ (float)x, (float)y });
                break;
            default:
                map.tiles[index] = TILE_EMPTY;
                break;
            }
        }
    }

    UnloadImageColors(pixels);
    UnloadImage(img);

    return map;
}

void UnloadMap(Map& map) {
    if (map.tiles != nullptr) {
        free(map.tiles);
        map.tiles = nullptr;
    }
    map.width = 0;
    map.height = 0;
}