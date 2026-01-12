#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "LoadTexture.h"
#include <cmath>

void EndereKistenPosition() {
    Kistenanzahl.clear();

    for (const Vector2& pos : Kisten) {
        Kiste neueKiste;
        neueKiste.Position = pos;
        neueKiste.timer = 25.0f;
        Kistenanzahl.push_back(neueKiste);
    }
}

void DrawKisten() {
    for (size_t i = 0; i < Kistenanzahl.size(); i++) {
        DrawTexture("kiste",
            Kistenanzahl[i].Position.x * TILE_SIZE,
            Kistenanzahl[i].Position.y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, WHITE);
    }
}