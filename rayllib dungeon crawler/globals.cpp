#include <cstdlib>
#include <ctime>
#include "globals.h"

int TILE_SIZE = 32;
Vector2 PlayerPosition = { 0, 0 };
Camera2D Maincam = { 0 };

void InitCamera() {
    Maincam.target = Vector2{ 0, 0 };
    Maincam.offset = Vector2{ 400, 225 }; 
    Maincam.rotation = 0.0f;
    Maincam.zoom = 4.0f;
}