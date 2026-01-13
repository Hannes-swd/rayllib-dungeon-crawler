#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "LoadTexture.h"
#include <cmath>
#include <iostream>

void Drop(std::string Item, int anzahl, int x, int y) {
    if (Item == "herz") {
        DropItem newDrop;
        newDrop.itemName = "herz";
        float offsetX = (rand() % 20 - 10) / 10.0f;
        float offsetY = (rand() % 20 - 10) / 10.0f;
        newDrop.position = Vector2{
            static_cast<float>(x) / TILE_SIZE + offsetX,
            static_cast<float>(y) / TILE_SIZE + offsetY
        };
        DropItems.push_back(newDrop);
    }
    if (Item == "energie") {
        DropItem newDrop;
        newDrop.itemName = "energie";
        float offsetX = (rand() % 20 - 10) / 10.0f;
        float offsetY = (rand() % 20 - 10) / 10.0f;
        newDrop.position = Vector2{
            static_cast<float>(x) / TILE_SIZE + offsetX,
            static_cast<float>(y) / TILE_SIZE + offsetY
        };
        DropItems.push_back(newDrop);
    }
}
void DrawDropItems() {
    for (size_t i = 0; i < DropItems.size(); i++) {
        if (DropItems[i].itemName == "herz") {
            DrawTexture(
                "Herz",
                DropItems[i].position.x * TILE_SIZE,
                DropItems[i].position.y * TILE_SIZE,
                TILE_SIZE * 0.5f,
                TILE_SIZE * 0.5f,
                WHITE
            );
        }
        if (DropItems[i].itemName == "energie") {
            DrawTexture(
                "energie_orb",
                DropItems[i].position.x * TILE_SIZE,
                DropItems[i].position.y * TILE_SIZE,
                TILE_SIZE * 0.5f,
                TILE_SIZE * 0.5f,
                WHITE
            );
        }
    }
}

void CollectDropItems() {
    for (size_t i = 0; i < DropItems.size(); ) {
        float distance = sqrt(
            pow(PlayerPosition.x - DropItems[i].position.x, 2) +
            pow(PlayerPosition.y - DropItems[i].position.y, 2)
        );

        if (distance < 0.8f) {
            bool itemCollected = false;

            if (DropItems[i].itemName == "herz") {
                SpielerLeben = std::min(SpielerLeben + 1, 10);
                itemCollected = true;
            }
            else if (DropItems[i].itemName == "energie") {
                if (energie < 10) {
                    energie++;
                    itemCollected = true;
                }
            }

            if (itemCollected) {
                DropItems.erase(DropItems.begin() + i);
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
