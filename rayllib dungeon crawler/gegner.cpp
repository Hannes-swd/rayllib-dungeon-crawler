#include "LoadMap.h"
#include "globals.h"
#include <cstdlib>
#include "LoadTexture.h"
#include <cmath>

void Spawngegner() {
	Vector2 spawnPoint = MobSpawner[std::rand() % MobSpawner.size()];
	Gegner newGegner;
	newGegner.position = spawnPoint;
	GegnerAnzahl.push_back(newGegner);
}
void ZeichneGegner() {
    for (size_t i = 0; i < GegnerAnzahl.size(); i++) {
        if (GegnerAnzahl[i].alive) {
            DrawTexture("Herz",
                GegnerAnzahl[i].position.x * TILE_SIZE,
                GegnerAnzahl[i].position.y * TILE_SIZE,
                32.0f,
                32.0f,
                WHITE);
			
        }
    }
}
void BewegeGegner(float deltaTime) {
        for (size_t i = 0; i < GegnerAnzahl.size(); i++) {
        if (GegnerAnzahl[i].alive) {
            Vector2 direction;
            direction.x = PlayerPosition.x - GegnerAnzahl[i].position.x;
            direction.y = PlayerPosition.y - GegnerAnzahl[i].position.y;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            if (length != 0) {
                direction.x /= length;
                direction.y /= length;
            }
            GegnerAnzahl[i].position.x += direction.x * GegnerAnzahl[i].speed * deltaTime;
            GegnerAnzahl[i].position.y += direction.y * GegnerAnzahl[i].speed * deltaTime;
        }
		}
}