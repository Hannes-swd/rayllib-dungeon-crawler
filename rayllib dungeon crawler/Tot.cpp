#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include "LoadTexture.h"

void TotAnzeigen() {
	ClearBackground(BLACK);
	DrawText("Du bist gestorben!", GetScreenWidth() / 2 - MeasureText("Du bist gestorben!", 40) / 2, GetScreenHeight() / 2 - 20, 40, RED);
	if (IsKeyPressed(KEY_ENTER)) {
		SpielerLeben = 10;
		PlayerPosition = PlayerSpawn;
		Tot = false;
	}
}