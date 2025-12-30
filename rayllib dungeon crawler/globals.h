#pragma once
#include "raylib.h"

extern int TILE_SIZE;
extern Vector2 PlayerPosition;
extern Camera2D Maincam;

void InitCamera();

extern int SpielerLeben;
extern float CurrentZoom;
void UpdateCameraZoom();

extern bool Tot;

extern Vector2 PlayerSpawn;