#pragma once

#include <string>
#include "raylib.h"

void loadTextures();
void unloadTextures();
void DrawTextureSize(const std::string& name,
    float x, float y,
    float width, float height,
    Color tint = WHITE);