#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"

extern Map map;

void CheckMoovment() {
    float moveSpeed = 5.0f;

    Vector2 newPosition = PlayerPosition;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        newPosition.x += moveSpeed * GetFrameTime();
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        newPosition.x -= moveSpeed * GetFrameTime();
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        newPosition.y -= moveSpeed * GetFrameTime();
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        newPosition.y += moveSpeed * GetFrameTime();
    }


    PlayerPosition = newPosition;
}