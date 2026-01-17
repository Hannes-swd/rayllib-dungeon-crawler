#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "LoadTexture.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void ZeichneMenü() {
	DrawCircle(50, 50, 50, RED);

    //geht raus
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