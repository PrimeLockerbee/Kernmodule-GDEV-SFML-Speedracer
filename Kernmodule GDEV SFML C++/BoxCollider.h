#pragma once

#include "Vector2.h"

class BoxCollider
{
public:
	// Constructors //
	BoxCollider();
	BoxCollider(Vector2 size, Vector2 pos);
	BoxCollider& operator=(const BoxCollider& boxCollider);

	// Public Methods //
	bool isCollidingWith(BoxCollider collider);
	bool isCollidingWithSideBorders(sf::RenderWindow& window);
	bool hasPassedBottomBorder(sf::RenderWindow& window);
	void updatePosition(Vector2 newPos);
	void calculateCorners();

private:
	// Private Variables //
	Vector2 size;
	Vector2 position;

	float bottomY;
	float topY;
	float leftX;
	float rightX;
};

