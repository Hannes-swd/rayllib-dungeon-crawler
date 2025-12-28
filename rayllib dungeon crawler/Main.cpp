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
    InitCamera();
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
        // Spielerbewegung zuerst
        CheckMoovment();

        // Kamera
        Maincam.target.x = PlayerPosition.x * TILE_SIZE;
        Maincam.target.y = PlayerPosition.y * TILE_SIZE;

        // Kamera-Offset
        Maincam.offset.x = GetScreenWidth() / 2.0f;
        Maincam.offset.y = GetScreenHeight() / 2.0f;

        // START ZEICHNEN
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(Maincam);

        // Map zeichnen
        DrawMap(map, TILE_SIZE);

        // Spieler zeichnen
        DrawPlayer();

        EndMode2D();


        EndDrawing();
    }
    //map unloaden
    UnloadMap(map);
    //texturen unloaden
    unloadTextures();
    CloseWindow();
    return 0;
}