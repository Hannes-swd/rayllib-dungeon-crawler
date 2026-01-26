#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "Menü.h"
#include "LoadTexture.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

void ZeichneMenü() {
	int windowWidth = GetScreenWidth();
    int windowHeight = GetScreenHeight();
    // Halbtransparenter Hintergrund
    DrawRectangle(0, 0, windowWidth, windowHeight, Color{ 0, 0, 0, 150 });
	//menü hintergrund
	DrawRectangle(windowWidth / 4, windowHeight / 4, windowWidth / 2, windowHeight / 2, Color{ 50, 50, 50, 255 });
    //text
	DrawText("Test Menü", windowWidth / 2 - MeasureText("Test Menü", 20) / 2, windowHeight / 4 + 20, 20, WHITE);
	// map zeigen

    DrawText(TextFormat("aktuelles Level: %d", akttuelleslvl),
        windowWidth / 2 - MeasureText(TextFormat("aktuelles Level: %d", akttuelleslvl), 20) / 2,
        windowHeight / 4 + 60, 20, WHITE);
    

    
    float previewSize = GetScreenWidth() / 2.0f * 0.35f;
    float previewX = GetScreenWidth() / 2 - previewSize / 2;
    float previewY = windowWidth / 2 - windowWidth /4;

    DrawTexture("map" + std::to_string(akttuelleslvl), previewX, previewY, previewSize, previewSize, WHITE);
    

    
    if (std::find(FreigeschalteteMaps.begin(), FreigeschalteteMaps.end(), akttuelleslvl) == FreigeschalteteMaps.end()) {
        //alles mit gesperten maüps
        DrawRectangle(previewX, previewY, previewSize, previewSize, Color{ 25, 25, 25, 255 });
        DrawRectangleLinesEx({ previewX, previewY, previewSize, previewSize }, 3, Color{ 60, 60, 60, 255 });
        DrawText(TextFormat("LEVEL %d", akttuelleslvl),
            previewX + previewSize / 2 - MeasureText(TextFormat("LEVEL %d", akttuelleslvl), 25) / 2,
            previewY + previewSize / 2 - 30, 25, GRAY);
        DrawText("GESPERRT",
            previewX + previewSize / 2 - MeasureText("GESPERRT", 20) / 2,
            previewY + previewSize / 2 + 10, 20, RED);
        
        DrawText("Kostet: 50",
            previewX + previewSize / 2 - MeasureText("Kostet: 50", 20) / 2,
            previewY + previewSize / 2 + 40, 20, RED);
        //map kaufen
        if (IsKeyPressed(KEY_ENTER)) {
            if (Geld >= 50) {
                FreigeschalteteMaps.push_back(akttuelleslvl);
                Geld -= 50;
            }
        }
        
            
        
        //schaut ob es  wechseln kann
        if (kannMapWechseln)
            kannMapWechseln = false;
	}
    else {
        kannMapWechseln = true;
    }

    //zeigt geld

    int kastenRechts = windowWidth / 4 * 3;
    int textBreite = MeasureText(TextFormat("%d", Geld), 40);
    int gesamtBreite = 64 + 10 + textBreite;
    int startX = kastenRechts - gesamtBreite - 20;

    DrawTexture("Geld", startX, windowHeight / 5 + 30, 64, 64);
    DrawText(TextFormat("%d", Geld), startX + 64 + 10, windowHeight / 5 + 40, 40, YELLOW);


    fensterschliesen();
    mependern();
}
void mependern() {
    
        if (IsKeyPressed(KEY_RIGHT) && akttuelleslvl <= levelanzahl) {
            akttuelleslvl++;
            menüGeendert = true;
        }
        if (IsKeyPressed(KEY_LEFT) && akttuelleslvl > 1) {
            akttuelleslvl--;
            menüGeendert = true;
        }
    
}
void fensterschliesen() {
    if (IsKeyPressed(KEY_ENTER) && !menüGeendert) {
        if (kannMapWechseln) {
            MenüOffen = false;
        }
    }
    if (menüGeendert == true && IsKeyUp(KEY_ENTER)) {
        if (kannMapWechseln) {
            menüGeendert = false;
        }
    }
}

void MapLaden(int level, Map& map) {
    
    UnloadMap(map);
    //zurücksetzen beim laden
    GegnerAnzahl.clear();
    MobSpawner.clear();
    DropItems.clear();
    Kistenanzahl.clear();
    Kisten.clear();
    Türen.clear();

    switch (level) {
    case 1:
        map = LoadMapFromImage("resources/Maps/map1.png");
        break;
    case 2:
        map = LoadMapFromImage("resources/Maps/map2.png");
        break;
    case 3:
        map = LoadMapFromImage("resources/Maps/map3.png");
        break;
    default:
        map = LoadMapFromImage("resources/Maps/map1.png");
        break;
    }

    PlayerPosition = PlayerSpawn;
    EndereKistenPosition();
    kistenanzahl = BerechneKistenAnzahl();
    LEtzteslvl = level;
}