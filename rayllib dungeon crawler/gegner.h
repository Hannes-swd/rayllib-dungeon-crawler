#pragma once

#include "raylib.h"
typedef struct Gegner {
    Vector2 position;
    int health = 10;
    int maxHealth = 10;
    bool alive = true;
    float speed = 2.0f;
} Gegner;

void Spawngegner();
void ZeichneGegner();
void BewegeGegner(float deltaTime);