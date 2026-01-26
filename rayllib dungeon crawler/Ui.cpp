#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include <algorithm>
#include "LoadTexture.h"

void DrawUi() {
	for (int i = 0; i < SpielerLeben; i++) {
		DrawTexture("Herz", 10 + i * 34, 5, 32, 32);
	}
	for (int i = 0; i < 10; i++) {
		if (i == 0 && energie > 0) {
			DrawTexture("Energie_1", 10 + i * 32, 50, 32, 32);
		}
		else if (i == 0 && energie <= 0) {
			DrawTexture("Energie_6", 10 + i * 32, 50, 32, 32);
		}
		else if (i == 9 && energie >= 10) {
			DrawTexture("Energie_3", 10 + i * 32, 50, 32, 32);
		}
		else if (i == 9 && energie < 10) {
			DrawTexture("Energie_4", 10 + i * 32, 50, 32, 32);
		}
		else if (i < energie && i > 0) {
			DrawTexture("Energie_2", 10 + i * 32, 50, 32, 32);
		}
		else if (i >= energie && i < 9) {
			DrawTexture("Energie_5", 10 + i * 32, 50, 32, 32);
		}
		
	}
	//Geld
	DrawTexture("Geld", 10, 90, 32, 32);
	DrawText(TextFormat("%d", Geld), 50, 93, 30, YELLOW);
	
	
	/*
	DrawText(TextFormat("Gegner: %d", GegnerAnzahl.size()), 10, 130, 50, RED);
	DrawText(TextFormat("Tueren: %d", Türen.size()), 10, 170, 50, RED);
	DrawText(TextFormat("Spawner: %d", MobSpawner.size()), 10, 210, 50, RED);
	
	DrawText(TextFormat("Leben: %d", SpielerLeben), 10, 50, 50, RED);
	DrawText(TextFormat("Position: (%.2f, %.2f)", PlayerPosition.x, PlayerPosition.y), 10, 90, 20, RED);
	*/
}