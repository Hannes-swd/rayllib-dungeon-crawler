// Main.cpp
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
#include "Ui.h"

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

    // FESTER ZOOM (entferne die automatische Berechnung)
    UpdateCameraZoom();
    //texturen laden
    loadTextures();

    while (!WindowShouldClose())
    {
        // Spielerbewegung zuerst
        CheckMoovment();

        if (IsWindowResized()) {
            Maincam.offset.x = GetScreenWidth() / 2.0f;
            Maincam.offset.y = GetScreenHeight() / 2.0f;
            UpdateCameraZoom();
        }

        // Kamera
        Maincam.target.x = PlayerPosition.x * TILE_SIZE;
        Maincam.target.y = PlayerPosition.y * TILE_SIZE;

        // START ZEICHNEN
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(Maincam);

        // Map zeichnen
        DrawMap(map, TILE_SIZE);

        // Spieler zeichnen
        DrawPlayer();

        EndMode2D();

        // UI zeichnen
        DrawUi();

        EndDrawing();
    }
    //map unloaden
    UnloadMap(map);
    //texturen unloaden
    unloadTextures();
    CloseWindow();
    return 0;
}