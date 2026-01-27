#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include "LoadTexture.h"

void TotAnzeigen() {
	SpielerLeben = 10;
	energie = 10;
	Geld = 0;
	PlayerPosition = PlayerSpawn;
	ClearBackground(BLACK);
	DrawText("Du bist gestorben!", GetScreenWidth() / 2 - MeasureText("Du bist gestorben!", 40) / 2, GetScreenHeight() / 2 - 20, 40, RED);
	DrawText("Drueck enter um zu respawnen", GetScreenWidth() / 2 - MeasureText("Drueck enter um zu respawnen", 40) / 2, GetScreenHeight() / 2 + 20, 40, RED);
	if (IsKeyPressed(KEY_ENTER)) 
		Tot = false;
	
}