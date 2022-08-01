#include "Time.h"

float Time::deltaTime = 0.0f;
sf::Clock Time::c_clock = sf::Clock();

float Time::CalculateDeltaTime()
{
	deltaTime = c_clock.restart().asSeconds();
	return deltaTime;
}

