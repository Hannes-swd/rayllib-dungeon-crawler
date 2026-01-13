#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "LoadTexture.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void EndereKistenPosition() {
    Kistenanzahl.clear();

    if (Kisten.empty() || kistenanzahl <= 0) {
        return;
    }

    std::srand(std::time(nullptr));

    std::vector<Vector2> verfügbarePositionen = Kisten;

    int anzahlZuWählen = std::min(kistenanzahl, (int)verfügbarePositionen.size());

    for (int i = 0; i < anzahlZuWählen; i++) {
        int randomIndex = std::rand() % verfügbarePositionen.size();

        Kiste neueKiste;
        neueKiste.Position = verfügbarePositionen[randomIndex];
        neueKiste.timer = 25.0f;
        Kistenanzahl.push_back(neueKiste);

        verfügbarePositionen.erase(verfügbarePositionen.begin() + randomIndex);

        if (verfügbarePositionen.empty()) {
            break;
        }
    }

    TraceLog(LOG_INFO, TextFormat("%d Kisten generiert von %d verfügbaren Positionen",
        (int)Kistenanzahl.size(), (int)Kisten.size()));
}

void DrawKisten() {
    for (size_t i = 0; i < Kistenanzahl.size(); i++) {
        DrawTexture("kiste",
            Kistenanzahl[i].Position.x * TILE_SIZE,
            Kistenanzahl[i].Position.y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, WHITE);
    }

    
}
void SammleKisten() {
    for (size_t i = 0; i < Kistenanzahl.size(); ) {
        float distanceToPlayer = std::sqrt(
            std::pow(PlayerPosition.x - Kistenanzahl[i].Position.x, 2) +
            std::pow(PlayerPosition.y - Kistenanzahl[i].Position.y, 2)
        );

        if (distanceToPlayer < 1.0f) {
            if (IsKeyPressed(KEY_E)) {
                Kistenanzahl.erase(Kistenanzahl.begin() + i);
                energie = std::min(energie + 1, 10);
                EndereKistenPosition();
                break;
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }
}