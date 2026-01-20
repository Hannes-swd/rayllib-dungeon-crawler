#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "Menü.h"
#include "LoadTexture.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void türÖfnen(Map& map) {
    float playerCenterX = PlayerPosition.x + 0.375f;
    float playerCenterY = PlayerPosition.y + 0.4f;
    for (int y = 0; y < map.height; y++) {
        for (int x = 0; x < map.width; x++) {
            TileType tile = map.tiles[y * map.width + x];
            if (tile == TILE_Tür) {
                float tileCenterX = x + 0.5f;
                float tileCenterY = y + 0.5f;
                float dx = playerCenterX - tileCenterX;
                float dy = playerCenterY - tileCenterY;
                float distance = std::sqrt(dx * dx + dy * dy);
                if (distance < 1.5f) {
                    if (IsKeyDown(KEY_E)) {
                        map.tiles[y * map.width + x] = TILE_Boden;
					}
					DrawTexture("ETaste",
                        x * TILE_SIZE + TILE_SIZE / 4,
                        y * TILE_SIZE - TILE_SIZE / 2,
                        TILE_SIZE / 2,
                        TILE_SIZE / 2,
						WHITE);
                    
                }
            }
        }
    }
}