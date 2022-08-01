#include <random>
#include "Math.h"

float Math::Abs(float value)
{
    if (value >= 0)
    {
        return value;
    }
    else  
    {
        return -value;
    }
}

//Restricts a number between two values
float Math::Clamp(float value, float minValue, float maxValue)
{
    if (value < minValue)
    {
        value = minValue;
    }
    else if (value > maxValue)
    {
        value = maxValue;
    }
    return value;
}

//Returns a random value between two numbers
float Math::RandomRange(float min, float max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(min, max);

    return dist(mt);
}

//Returns a -1 or 1
int Math::RandomGetSign()
{
    float random = Math::RandomRange(0.0f, 1.0f);
    if (random < 0.50f)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}


