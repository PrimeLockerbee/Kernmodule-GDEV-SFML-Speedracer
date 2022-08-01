#pragma once
#include "Character.h";
#include "Timer.h";

class Enemy : public Character
{
public:
	Enemy(Vector2 size, sf::Color playerColor, Vector2 startPos);

	virtual void onUpdate(sf::RenderWindow& window);
	bool isOutOfScreen(sf::RenderWindow& window);
	virtual void draw(sf::RenderWindow& window);

private:
	RectRenderer rectRenderer;
	Vector2 downwardForce;
	Timer acceleratingTimer;
	Timer brakingTimer;
	bool isAccelerating;

	void tickTimers();
	void switchToAccelerating();
	void switchToBraking();
};


