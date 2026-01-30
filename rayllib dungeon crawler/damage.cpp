#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include <cmath>

void DealPlayerDamage(int damage) {
	SpielerLeben -= damage;
	if (SpielerLeben <= 0) {
		Tot = true;
	}
}