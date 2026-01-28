#pragma once

#include "raylib.h"

typedef struct Gegner {
    Vector2 position;
    int health = 10;
    int maxHealth = 10;
    bool alive = true;
    float speed = 2.0f;
    float sightRange = 5.0f;
    float wanderTimer = 0.0f;
    Vector2 wanderDirection = { 0, 0 };
    int Typ;
} Gegner;

void Spawngegner();
void ZeichneGegner();
void BewegeGegner(float deltaTime);
void GEgnerSchaden();
void spielerSchaden();