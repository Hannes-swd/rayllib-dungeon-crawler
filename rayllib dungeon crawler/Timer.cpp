#include "Timer.h"

void Timer::start(float duration)
{
    timeLeft = duration;
}

void Timer::update(float deltaTime)
{
    if (timeLeft > 0.0f)
        timeLeft -= deltaTime;
}

bool Timer::finished() const
{
    return timeLeft <= 0.0f;
}
