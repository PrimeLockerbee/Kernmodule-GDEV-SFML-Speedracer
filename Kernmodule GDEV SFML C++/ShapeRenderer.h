#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class ShapeRenderer
{
public:
	Vector2 shapePosition;
	sf::Color shapeColor;

	void SetShapePosition(Vector2 pos);
	virtual void drawShape(sf::RenderWindow& window) = 0;
};

