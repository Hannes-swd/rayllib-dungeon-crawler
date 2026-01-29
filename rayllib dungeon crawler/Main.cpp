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
#include "Kiste.h"
#include "Menü.h"
#include "Tür.h"
#include "Speed.h"
Map map;


/*

if (Speed.finished())
    DrawText("Sprint aktiv!", 10, 10, 100, GREEN);
            
*/
int main(void)
{
    Image icon = LoadImage("resources/Logo/Logo.png");
    //programm infos
    const int screenWidth = 800;
    const int screenHeight = 450;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Room runner");
    SetWindowIcon(icon);
    UnloadImage(icon);

    InitCamera();
    SetTargetFPS(60);

    // ERSTE MAP LADEN
    MapLaden(akttuelleslvl, map);

    if (map.tiles == nullptr) {
        TraceLog(LOG_ERROR, "Failed to load map!");
        CloseWindow();
        return -1;
    }

    // Kisten setzen
    EndereKistenPosition();

    // FESTER ZOOM
    UpdateCameraZoom();
    //texturen laden
    loadTextures();

    //timer 
    Timer DamageTimer;
    DamageTimer.start(1.0f);
    Speed.start(0.0f);

    //mobspawn
    int mobspawncowntdown = 100;

    while (!WindowShouldClose())
    {
        SetExitKey(KEY_NULL);

        //wechselt in esc menü
        if (!MenüOffen && IsKeyPressed(KEY_ESCAPE)) {
            MenüOffen = true;
            menüGeendert = true;
        }
            

        //aktualisiert wen aktuelle map nicht ist
        if (akttuelleslvl != LEtzteslvl) {
            GegnerAnzahl.clear();
            MobSpawner.clear();
            DropItems.clear();
            Kistenanzahl.clear();
            Kisten.clear();
            Türen.clear();

            MapLaden(akttuelleslvl, map);
        }

        //timer - Hier deltaTime mit GetFrameTime() definieren
        float deltaTime = GetFrameTime();
        DamageTimer.update(deltaTime);
        Speed.update(deltaTime);

        // Spielerbewegung zuerst
        if (!Tot && !MenüOffen) {
            CheckMoovment();
        }

        if (IsWindowResized()) {
            Maincam.offset.x = GetScreenWidth() / 2.0f;
            Maincam.offset.y = GetScreenHeight() / 2.0f;
            UpdateCameraZoom();
        }

        // Prüfen ob Position innerhalb der Map ist
        int playerTileX = (int)PlayerPosition.x;
        int playerTileY = (int)PlayerPosition.y;

        if (playerTileX >= 0 && playerTileX < map.width &&
            playerTileY >= 0 && playerTileY < map.height) {

            //wen spieler in lava ist
            if (map.tiles[playerTileY * map.width + playerTileX] == TILE_LAVA) {
                if (DamageTimer.finished()) {
                    DealPlayerDamage(1);

                    DamageTimer.start(0.5f);
                }
            }

            //langsam wen er im wasser ist
            if (map.tiles[playerTileY * map.width + playerTileX] == TILE_WATER) {
                PlayerSpeed = 1.0f;
            }
            else {
                PlayerSpeed = 3.0f;
            }
        }

        //mob spawn - NUR wenn Menü geschlossen ist
        if (GegnerAnzahl.size() < 10 && !MenüOffen) {
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

        //kisten
        DrawKisten();

		// tür öffnen
        türÖffnenUndSchließen(map, deltaTime);
        ZeichneTüren();
        //kiste sammeln
        SammleKisten();

        //gegner
        ZeichneGegner();
        if (!MenüOffen) {
            BewegeGegner(deltaTime);
            GEgnerSchaden();
            spielerSchaden();
        }

        // drops anzeigen
        DrawDropItems();
        CollectDropItems();
        SpeedEffect();

        EndMode2D();

        // UI zeichnen
        if (Tot) {
            TotAnzeigen();
        }
        else {
            DrawUi();
        }

        if (MenüOffen) {
            ZeichneMenü();
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