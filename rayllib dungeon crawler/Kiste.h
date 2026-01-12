#pragma once
#include "raylib.h"

void EndereKistenPosition();
void DrawKisten();

typedef struct Kiste {
    Vector2 Position;
    float timer = 25;
} Kiste;