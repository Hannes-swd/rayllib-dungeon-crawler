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
}