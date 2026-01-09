// globals.cpp
#include <cstdlib>
#include <ctime>
#include "globals.h"

//akttuelleslvl
int akttuelleslvl = 1;

int TILE_SIZE = 32;
Vector2 PlayerPosition = { 0, 0 };
Camera2D Maincam = { 0 };

float PlayerSpeed = 3.0f;

void InitCamera() {
    Maincam.target = Vector2{ 0, 0 };
    Maincam.offset = Vector2{ 400, 225 };
    Maincam.rotation = 0.0f;
    Maincam.zoom = 1.0f;
}

float CurrentZoom = 1.0f;

void UpdateCameraZoom() {
    float screenWidth = (float)GetScreenWidth();
    float screenHeight = (float)GetScreenHeight();

    // sichtfeld
    float targetTilesWidth = 10.0f;

    CurrentZoom = screenWidth / (targetTilesWidth * TILE_SIZE);
    Maincam.zoom = CurrentZoom;
}

int SpielerLeben = 10;

bool Tot = false;


Vector2 PlayerSpawn = { 1.0f, 1.0f };

//gegner
std::vector<Vector2> MobSpawner;
std::vector<Gegner> GegnerAnzahl;

// Drop-Items
std::vector<DropItem> DropItems;