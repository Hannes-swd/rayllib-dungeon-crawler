#include "raylib.h"
#include <unordered_map>
#include <string>
#include "LoadTexture.h"
#include "Timer.h"
int main(void)
{
    //programm infos
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Dungeon crawler");
    SetTargetFPS(60);

    //CODE METODEN
    
    //texturen laden
    loadTextures();

    //Alle timer:
    
    
    while (!WindowShouldClose())
    {
        //timer:

        

        //START ZEICHNEN
        BeginDrawing();
        ClearBackground(RAYWHITE);

        

        EndDrawing();
    }
    //texturen unloaden
    unloadTextures();
    CloseWindow();
    return 0;
}