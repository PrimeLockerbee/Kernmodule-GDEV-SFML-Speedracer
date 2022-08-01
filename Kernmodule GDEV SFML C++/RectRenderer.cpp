#include "RectRenderer.h"

RectRenderer::RectRenderer()
{
	width = 100;
	height = 100;
}

RectRenderer::RectRenderer(float rectWidth, float rectHeight, sf::Color shapeColor)
{
	width = rectWidth;
	height = rectHeight;
	this->shapeColor = shapeColor;
	Vector2 sizeVector = Vector2(rectWidth, rectHeight);
	shape.setSize(sizeVector.ToSFMLVector2f());
	shape.setFillColor(shapeColor);
}

void RectRenderer::drawShape(sf::RenderWindow& window)
{
	shape.setPosition(shapePosition.ToSFMLVector2f());
	window.draw(shape);
}

void RectRenderer::setAlpha(float alpha)
{
	shapeColor.a = alpha;
	shape.setFillColor(shapeColor);
}
