#include "raylib.h"
#include "globals.h"
#include "LoadMap.h"
#include "LoadTexture.h"
#include <cmath>
#include <iostream>

void SpeedEffect() {
    if (!Speed.finished()) {
        if (PlayerSpeed != 5.0f)
            PlayerSpeed = 5.0f;
    }
    else {
        if (PlayerSpeed != 3.0f)
            PlayerSpeed = 3.0f;
    }
}