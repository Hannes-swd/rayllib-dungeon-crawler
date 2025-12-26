#include "raylib.h"
#include <unordered_map>
#include <string>
#include "LoadTexture.h"
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Dungeon crawler");
    loadTextures();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureSize("test", 10, 10, 100, 100);

        EndDrawing();
    }
    unloadTextures();
    CloseWindow();
    return 0;
}