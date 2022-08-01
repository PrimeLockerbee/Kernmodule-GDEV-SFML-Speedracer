#pragma once
#include "ShapeRenderer.h"

class RectRenderer : public ShapeRenderer
{
public:
	float width;
	float height;

	RectRenderer();
	RectRenderer(float rectWidth, float rectHeight, sf::Color shapeColor);
	void drawShape(sf::RenderWindow& window);
	void setAlpha(float alpha);

private:
	sf::RectangleShape shape;
};

