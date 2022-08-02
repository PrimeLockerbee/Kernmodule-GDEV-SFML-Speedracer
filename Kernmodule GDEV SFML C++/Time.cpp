#include "Time.h"

float Time::deltaTime = 0.0f;
sf::Clock Time::c_clock = sf::Clock();

//Calculates the deltatime
float Time::CalculateDeltaTime()
{
	deltaTime = c_clock.restart().asSeconds();
	return deltaTime;
}

