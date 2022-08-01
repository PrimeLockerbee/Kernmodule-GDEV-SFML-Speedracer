#pragma once
#include <SFML/System/Clock.hpp>

class Time
{
	public:
		static float deltaTime;
		static float CalculateDeltaTime();
	
	private:
		static sf::Clock c_clock;
};

