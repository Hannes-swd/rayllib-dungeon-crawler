#pragma once
#include "raylib.h"

void EndereKistenPosition();
void DrawKisten();
void SammleKisten();

typedef struct Kiste {
    Vector2 Position;
    float timer = 25;
} Kiste;