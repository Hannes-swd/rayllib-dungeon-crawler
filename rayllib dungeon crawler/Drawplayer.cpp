#include "raylib.h"
#include "LoadTexture.h"
#include "globals.h"

void DrawPlayer() {
    float playerWidth = TILE_SIZE * 0.75f;
    float playerHeight = TILE_SIZE * 0.75f;

    float offsetX = (TILE_SIZE - playerWidth) / 2.0f;
    float offsetY = (TILE_SIZE - playerHeight) / 2.0f;

    DrawTexture("Player",
        PlayerPosition.x * TILE_SIZE + offsetX,
        PlayerPosition.y * TILE_SIZE + offsetY,
        playerWidth,
        playerHeight);
}