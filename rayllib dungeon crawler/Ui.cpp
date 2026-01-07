#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include "LoadTexture.h"

void DrawUi() {
	for (int i = 0; i < SpielerLeben; i++) {
		DrawTexture("Herz", 10 + i * 34, 5, 32, 32);
	}
	
	DrawText(TextFormat("Spawner: %d", MobSpawner.size()), 10, 30, 50, RED);
	DrawText(TextFormat("Gegner: %d", GegnerAnzahl.size()), 10, 70, 50, RED);
	/*
	DrawText(TextFormat("Leben: %d", SpielerLeben), 10, 50, 50, RED);
	DrawText(TextFormat("Position: (%.2f, %.2f)", PlayerPosition.x, PlayerPosition.y), 10, 90, 20, RED);
	*/
}