#pragma once

struct Timer
{
    float timeLeft = 0.0f;

    void start(float duration);

    void update(float deltaTime);

    bool finished() const;
};
