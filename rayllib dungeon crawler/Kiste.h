#pragma once

#include "raylib.h"
void EndereKistenPosition();

typedef struct Kiste {
	Vector2 Position;
	float timer = 25;
}Kiste;