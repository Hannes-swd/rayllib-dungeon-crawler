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
#include "damage.h"
#include "Tot.h"

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
    switch (akttuelleslvl)
    {
    case 1:
        map = LoadMapFromImage("resources/map1.png");
        break;
    case 2:
        map = LoadMapFromImage("resources/map2.png");
    default:
        break;
    }
    
    
    
    if (map.tiles == nullptr) {
        TraceLog(LOG_ERROR, "Failed to load map!");
        CloseWindow();
        return -1;
    }

    // FESTER ZOOM
    UpdateCameraZoom();
    //texturen laden
    loadTextures();

    //timer 
    Timer DamageTimer;
    DamageTimer.start(1.0f);

    //mobspawn
    int mobspawncowntdown = 100;

    while (!WindowShouldClose())
    {
        //timer - Hier deltaTime mit GetFrameTime() definieren
        float deltaTime = GetFrameTime();
        DamageTimer.update(deltaTime);

        // Spielerbewegung zuerst
        if (!Tot) {
            CheckMoovment();
        }


        if (IsWindowResized()) {
            Maincam.offset.x = GetScreenWidth() / 2.0f;
            Maincam.offset.y = GetScreenHeight() / 2.0f;
            UpdateCameraZoom();
        }

        //wen spieler in lava ist
        if (map.tiles[(int)PlayerPosition.y * map.width + (int)PlayerPosition.x] == TILE_LAVA) {
            if (DamageTimer.finished()) {
                DealPlayerDamage(1);
                DamageTimer.start(0.5f);
            }
        }
        //langsam wen er im wasser ist
        if (map.tiles[(int)PlayerPosition.y * map.width + (int)PlayerPosition.x] == TILE_WATER) {
            PlayerSpeed = 1.0f;
        }
        else {
            PlayerSpeed = 3.0f;
        }


        //mob spawn
        if (GegnerAnzahl.size() < 10) {
            
            if (GegnerAnzahl.size() < 5) {
                if (mobspawncowntdown < 1) {
                    mobspawncowntdown = 100 + (std::rand() % 501); // 100-600
                    Spawngegner();
                }
                else {
                    mobspawncowntdown--;
                }
            }
            else {
                if (mobspawncowntdown < 1) {
                    mobspawncowntdown = 100 + (std::rand() % 901); // 100-1000
                    Spawngegner();
                }
                else {
                    mobspawncowntdown--;
                }
            }
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

        //gegner
        ZeichneGegner();
		BewegeGegner(deltaTime);
        GEgnerSchaden();

        EndMode2D();

        

        // UI zeichnen
        if (Tot) {
            TotAnzeigen();
        }
        else {
            DrawUi();
        }

        

        EndDrawing();
    }
    //map unloaden
    UnloadMap(map);
    //texturen unloaden
    unloadTextures();
    CloseWindow();
    return 0;
}