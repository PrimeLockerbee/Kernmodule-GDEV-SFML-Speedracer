#pragma once

#include "Vector2.h"
#include "Character.h"
#include <SFML/Graphics.hpp>
#include "Timer.h"

class Player : public Character
{
public:
	// Constructors //
	Player();
	Player(Vector2 size, sf::Color playerColor);
	Player& operator=(const Player& player);

	// Public Methods //
	void onUpdate(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void onCollision();
	int getLives();

private:
	// Private Variables //
	RectRenderer rectRenderer;
	int horizontalInput;
	int lives;

	bool isInvincable;
	Timer invincabilityTimer;

	// Private Methods //
	int getInputHorizontal();
	void tickInvincabilityTimer();
};

