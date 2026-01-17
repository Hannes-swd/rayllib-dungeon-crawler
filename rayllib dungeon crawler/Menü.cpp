#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "Menü.h"
#include "LoadTexture.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void ZeichneMenü() {
	int windowWidth = GetScreenWidth();
    int windowHeight = GetScreenHeight();
    // Halbtransparenter Hintergrund
    DrawRectangle(0, 0, windowWidth, windowHeight, Color{ 0, 0, 0, 150 });
	//menü hintergrund
	DrawRectangle(windowWidth / 4, windowHeight / 4, windowWidth / 2, windowHeight / 2, Color{ 50, 50, 50, 255 });
    //text
	DrawText("Test Menü", windowWidth / 2 - MeasureText("Test Menü", 20) / 2, windowHeight / 4 + 20, 20, WHITE);
	// map bild mittig zeichnen
    

    fensterschliesen();
}
void fensterschliesen() {
    if (IsKeyPressed(KEY_ESCAPE) && !menüGeendert) {

        MenüOffen = false;
    }
    if (menüGeendert == true && IsKeyUp(KEY_ESCAPE)) {
        menüGeendert = false;
    }
}

void MapLaden(int level, Map& map) {
    UnloadMap(map);

    switch (level) {
    case 1:
        map = LoadMapFromImage("resources/map1.png");
        break;
    case 2:
        map = LoadMapFromImage("resources/map2.png");
        break;
    default:
        map = LoadMapFromImage("resources/map1.png");
        break;
    }

    PlayerPosition = PlayerSpawn;

    LEtzteslvl = level;
}