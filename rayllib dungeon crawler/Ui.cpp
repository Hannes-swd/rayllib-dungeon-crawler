#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include "LoadTexture.h"

void DrawUi() {
	for (int i = 0; i < SpielerLeben; i++) {
		DrawTexture("Herz", 10 + i * 34, 5, 32, 32);
	}
	for (int i = 0; i < energie; i++) {
		if (i == 0) {
			DrawTexture("Energie_1", 10 + i * 32, 50, 32, 32);
		}
		else if (i == energie - 1) {
			DrawTexture("Energie_3", 10 + i * 32, 50, 32, 32);
		}
		else {
			DrawTexture("Energie_2", 10 + i * 32, 50, 32, 32);
		}
		
	}
	
	DrawText(TextFormat("Spawner: %d", MobSpawner.size()), 10, 90, 50, RED);
	DrawText(TextFormat("Gegner: %d", GegnerAnzahl.size()), 10, 130, 50, RED);
	/*
	DrawText(TextFormat("Leben: %d", SpielerLeben), 10, 50, 50, RED);
	DrawText(TextFormat("Position: (%.2f, %.2f)", PlayerPosition.x, PlayerPosition.y), 10, 90, 20, RED);
	*/
}