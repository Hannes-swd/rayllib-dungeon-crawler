#include "LoadMap.h"
#include "globals.h"
#include "LoadTexture.h"
#include "damage.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
extern Map map;

bool CanSeePlayer(const Vector2& gegnerPos, const Vector2& playerPos, const Map& map) {
    float dx = playerPos.x - gegnerPos.x;
    float dy = playerPos.y - gegnerPos.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    if (distance < 0.1f) return true;

    dx /= distance;
    dy /= distance;

    float stepSize = 0.25f;
    int steps = (int)(distance / stepSize);

    for (int i = 1; i <= steps; i++) {
        float x = gegnerPos.x + dx * stepSize * i;
        float y = gegnerPos.y + dy * stepSize * i;

        int tileX = (int)std::floor(x);
        int tileY = (int)std::floor(y);

        if (tileX < 0 || tileX >= map.width || tileY < 0 || tileY >= map.height) {
            return false;
        }

        TileType tile = map.tiles[tileY * map.width + tileX];
        if (tile == TILE_Wand) {
            return false;
        }
    }

    return true;
}

Vector2 GetRandomDirection() {
    float angle = (std::rand() % 360) * (3.14159f / 180.0f);
    return Vector2{ std::cos(angle), std::sin(angle) };
}

bool IsValidPosition(const Vector2& pos, const Map& map) {
    int tileX = (int)std::floor(pos.x);
    int tileY = (int)std::floor(pos.y);

    if (tileX < 0 || tileX >= map.width || tileY < 0 || tileY >= map.height) {
        return false;
    }

    TileType tile = map.tiles[tileY * map.width + tileX];
    return (tile != TILE_Wand);
}

void Spawngegner() {
    if (MobSpawner.empty()) return;

    Vector2 spawnPoint = MobSpawner[std::rand() % MobSpawner.size()];
    Gegner newGegner;
    newGegner.position = spawnPoint;
    newGegner.sightRange = 5.0f;
    newGegner.wanderTimer = (std::rand() % 100) * 0.01f;
    newGegner.wanderDirection = GetRandomDirection();
    GegnerAnzahl.push_back(newGegner);
}

void ZeichneGegner() {
    for (size_t i = 0; i < GegnerAnzahl.size(); i++) {
        if (GegnerAnzahl[i].alive) {
            DrawTexture("Zaber",
                GegnerAnzahl[i].position.x * TILE_SIZE,
                GegnerAnzahl[i].position.y * TILE_SIZE,
                32.0f,
                32.0f,
                WHITE);
        }
    }
}

void BewegeGegner(float deltaTime) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(nullptr));
        seeded = true;
    }

    for (size_t i = 0; i < GegnerAnzahl.size(); i++) {
        if (!GegnerAnzahl[i].alive) continue;

        float distanceToPlayer = std::sqrt(
            std::pow(PlayerPosition.x - GegnerAnzahl[i].position.x, 2) +
            std::pow(PlayerPosition.y - GegnerAnzahl[i].position.y, 2)
        );

        Vector2 direction = { 0, 0 };
        bool chasePlayer = false;

        if (distanceToPlayer <= GegnerAnzahl[i].sightRange) {
            if (CanSeePlayer(GegnerAnzahl[i].position, PlayerPosition, map)) {
                chasePlayer = true;
                direction.x = PlayerPosition.x - GegnerAnzahl[i].position.x;
                direction.y = PlayerPosition.y - GegnerAnzahl[i].position.y;
            }
        }

        if (!chasePlayer) {
            GegnerAnzahl[i].wanderTimer -= deltaTime;

            if (GegnerAnzahl[i].wanderTimer <= 0) {
                GegnerAnzahl[i].wanderDirection = GetRandomDirection();
                GegnerAnzahl[i].wanderTimer = 1.0f + (std::rand() % 200) * 0.01f;
            }

            direction = GegnerAnzahl[i].wanderDirection;
        }

        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0.001f) {
            direction.x /= length;
            direction.y /= length;
        }

        Vector2 oldPos = GegnerAnzahl[i].position;
        Vector2 newPos = oldPos;

        newPos.x += direction.x * GegnerAnzahl[i].speed * deltaTime;
        newPos.y += direction.y * GegnerAnzahl[i].speed * deltaTime;

        if (IsValidPosition(newPos, map)) {
            GegnerAnzahl[i].position = newPos;
        }
        else {
            GegnerAnzahl[i].wanderTimer = 0;
        }

        GegnerAnzahl[i].position.x = std::max(0.0f, std::min((float)map.width - 0.1f, GegnerAnzahl[i].position.x));
        GegnerAnzahl[i].position.y = std::max(0.0f, std::min((float)map.height - 0.1f, GegnerAnzahl[i].position.y));
    }
}
void GEgnerSchaden() {
    for (size_t i = 0; i < GegnerAnzahl.size(); ) {
        if (!GegnerAnzahl[i].alive) {
            GegnerAnzahl.erase(GegnerAnzahl.begin() + i);
            continue;
        }

        float distanceToPlayer = std::sqrt(
            std::pow(PlayerPosition.x - GegnerAnzahl[i].position.x, 2) +
            std::pow(PlayerPosition.y - GegnerAnzahl[i].position.y, 2)
        );

        if (distanceToPlayer < 0.8f) {
            DealPlayerDamage(1);
            GegnerAnzahl[i].alive = false;
        }
        i++;
    }
}