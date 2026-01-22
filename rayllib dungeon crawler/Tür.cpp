#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "Menü.h"
#include "LoadTexture.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void türÖffnenUndSchließen(Map& map, float deltaTime) {
    float playerCenterX = PlayerPosition.x + 0.375f;
    float playerCenterY = PlayerPosition.y + 0.4f;

    for (auto& tür : Türen) {
        if (tür.offen) {
            tür.schließTimer.update(deltaTime);

            if (tür.schließTimer.finished()) {
                tür.offen = false;

                int tileX = (int)tür.Position.x;
                int tileY = (int)tür.Position.y;
                if (tileX >= 0 && tileX < map.width &&
                    tileY >= 0 && tileY < map.height) {
                    map.tiles[tileY * map.width + tileX] = TILE_Tür;
                }
            }
        }
    }

    for (auto& tür : Türen) {
        if (!tür.offen) {
            float tileCenterX = tür.Position.x + 0.5f;
            float tileCenterY = tür.Position.y + 0.5f;
            float dx = playerCenterX - tileCenterX;
            float dy = playerCenterY - tileCenterY;
            float distance = std::sqrt(dx * dx + dy * dy);

            if (distance < 1.5f) {
                
                DrawTexture("ETaste",
                    tür.Position.x * TILE_SIZE + TILE_SIZE / 4,
                    tür.Position.y * TILE_SIZE - TILE_SIZE / 2,
                    TILE_SIZE / 2,
                    TILE_SIZE / 2,
                    WHITE);

                // Tür ofnen
                if (IsKeyDown(KEY_E)) {
                    tür.offen = true;
                    tür.schließTimer.start(5.0f);
                    //map zeichnen
                    int tileX = (int)tür.Position.x;
                    int tileY = (int)tür.Position.y;
                    if (tileX >= 0 && tileX < map.width &&
                        tileY >= 0 && tileY < map.height) {
                        map.tiles[tileY * map.width + tileX] = TILE_Boden;
                    }
                }
            }
        }
    }
}

void ZeichneTüren() {
    for (const auto& tür : Türen) {
        if (!tür.offen) {
            DrawTexture("tür_textur",
                tür.Position.x * TILE_SIZE,
                tür.Position.y * TILE_SIZE,
                TILE_SIZE,
                TILE_SIZE,
                WHITE);

            // Timer
            if (tür.offen) {
                float timerProgress = 1.0f - (tür.schließTimer.timeLeft / 5.0f);
                DrawRectangle(
                    tür.Position.x * TILE_SIZE,
                    tür.Position.y * TILE_SIZE - 5,
                    TILE_SIZE * timerProgress,
                    3,
                    YELLOW
                );
            }
        }
    }
}