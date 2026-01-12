#pragma once
#include "raylib.h"
#include <vector>
#include "gegner.h"
#include "Kiste.h"
#include "drop.h"

//aktuelles levl
extern int akttuelleslvl;

extern int TILE_SIZE;
extern Vector2 PlayerPosition;
extern Camera2D Maincam;

void InitCamera();

extern int energie;

extern int SpielerLeben;
extern float CurrentZoom;
void UpdateCameraZoom();

extern bool Tot;

extern Vector2 PlayerSpawn;

extern float PlayerSpeed;

//gegner
extern std::vector<Vector2> MobSpawner;

extern std::vector<Gegner> GegnerAnzahl;

// Drop-Items
extern std::vector<DropItem> DropItems;

//kisten
extern std::vector<Vector2> Kisten;
extern std::vector<Kiste> Kistenanzahl;

extern void EndereKistenPosition();
extern void DrawKisten();