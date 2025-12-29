#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include "LoadTexture.h"

void DrawUi() {
	

	for (int i = 0; i < SpielerLeben; i++) {
		DrawTexture("Herz", 10 + i * 34, 5, 32, 32);
	}
}