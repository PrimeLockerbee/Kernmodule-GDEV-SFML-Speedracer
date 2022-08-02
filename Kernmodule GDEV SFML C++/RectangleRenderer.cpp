#include "RectangleRenderer.h"

RectangleRenderer::RectangleRenderer()
{
	f_width = 100;
	f_height = 100;
}

RectangleRenderer::RectangleRenderer(float rectWidth, float rectHeight, sf::Color shapeColor)
{
	f_width = rectWidth;
	f_height = rectHeight;
	this->c_ShapeColor = shapeColor;
	Vector2 sizeVector = Vector2(rectWidth, rectHeight);
	rs_shape.setSize(sizeVector.ToSFMLVector2f());
	rs_shape.setFillColor(shapeColor);
}

void RectangleRenderer::DrawShape(sf::RenderWindow& window)
{
	rs_shape.setPosition(v2_ShapePosition.ToSFMLVector2f());
	window.draw(rs_shape);
}

void RectangleRenderer::SetAlpha(float alpha)
{
	c_ShapeColor.a = alpha;
	rs_shape.setFillColor(c_ShapeColor);
}
