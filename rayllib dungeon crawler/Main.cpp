#include "raylib.h"
#include <unordered_map>
#include <string>
#include "globals.h"
#include "LoadTexture.h"
#include "Timer.h"
#include "LoadMap.h"
#include "DrawMap.h"
#include "Drawplayer.h"
#include "PlayerMovment.h"


Map map;

int main(void)
{
    //programm infos
    const int screenWidth = 800;
    const int screenHeight = 450;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
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

        //map zeichnen
        DrawMap(map, TILE_SIZE);

        //spieler zeichnen
        DrawPlayer();
        //spielerrmoovment
        CheckMoovment();


        EndDrawing();
    }
    //map unloaden
    UnloadMap(map);
    //texturen unloaden
    unloadTextures();
    CloseWindow();
    return 0;
}