#include "raylib.h"
#include <unordered_map>
#include <string>
#include "LoadTexture.h"
#include "Timer.h"
#include "LoadMap.h"
#include "DrawMap.h"

const int TILE_SIZE = 32;
Map map;

int main(void)
{
    //programm infos
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Dungeon crawler");
    SetTargetFPS(60);

    //map laden
    map = LoadMapFromImage("resources/map.png");
    if (map.tiles == nullptr) {
        TraceLog(LOG_ERROR, "Failed to load map!");
        CloseWindow();
        return -1;
    }
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

        DrawMap(map, TILE_SIZE);

        EndDrawing();
    }
    //map unloaden
    UnloadMap(map);
    //texturen unloaden
    unloadTextures();
    CloseWindow();
    return 0;
}