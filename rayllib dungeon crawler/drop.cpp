#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include <cmath>
#include <iostream>

void Drop(std::string Item, int anzahl, int x, int y) {
	if (Item == "herz") {
		for (int i = 0; i < anzahl; i++) {
			if (SpielerLeben < 10) {
				SpielerLeben++;
			}
		}
	}
}