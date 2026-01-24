#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include <cmath>

extern Map map;

bool CanPlayerBeAt(Vector2 position) {

    float playerLeft = position.x;
    float playerRight = position.x + 0.75f;
    float playerTop = position.y;
    float playerBottom = position.y + 0.8f;

    int startX = (int)floor(playerLeft);
    int endX = (int)ceil(playerRight);
    int startY = (int)floor(playerTop);
    int endY = (int)ceil(playerBottom);

    for (int y = startY; y < endY; y++) {
        for (int x = startX; x < endX; x++) {
            if (x < 0 || x >= map.width || y < 0 || y >= map.height) {
                return false; 
            }

            TileType tile = map.tiles[y * map.width + x];
            if (tile == TILE_Wand || tile == TILE_Tür) {
                return false;
            }
        }
    }

    return true;
}

void CheckMoovment() {
    float moveSpeed = PlayerSpeed;
    Vector2 newPosition = PlayerPosition;

    Vector2 oldPosition = PlayerPosition;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        newPosition.x += moveSpeed * GetFrameTime();
        gehrichtung = 2;
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) { 
        newPosition.x -= moveSpeed * GetFrameTime(); 
        gehrichtung = 3;
    }

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        newPosition.y -= moveSpeed * GetFrameTime();
        gehrichtung = 4;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        newPosition.y += moveSpeed * GetFrameTime();
        gehrichtung = 1;
    }

    if (CanPlayerBeAt(newPosition)) {
        PlayerPosition = newPosition;
    }
    else {
        Vector2 testX = oldPosition;
        testX.x = newPosition.x;
        if (CanPlayerBeAt(testX)) {
            PlayerPosition = testX;
        }

        Vector2 testY = oldPosition;
        testY.y = newPosition.y;
        if (CanPlayerBeAt(testY)) {
            PlayerPosition.y = testY.y;
        }
    }
}