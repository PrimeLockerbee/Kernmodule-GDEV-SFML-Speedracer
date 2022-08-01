#include "Math.h"
#include <random>

float Math::Abs(float value)
{
    if (value >= 0) return value;
    else return -value;
}

float Math::Clamp(float value, float minValue, float maxValue)
{
    if (value < minValue) value = minValue;
    else if (value > maxValue) value = maxValue;
    return value;
}

float Math::randomRange(float min, float max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(min, max);

    return dist(mt);
}
// Returns either 1 or -1
int Math::getRandomSign()
{
    float random = Math::randomRange(0.0f, 1.0f);
    if (random < 0.50f) return -1;
    else return 1;
}


