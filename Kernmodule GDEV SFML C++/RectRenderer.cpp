#include "RectRenderer.h"

RectRenderer::RectRenderer()
{
	f_width = 100;
	f_height = 100;
}

RectRenderer::RectRenderer(float rectWidth, float rectHeight, sf::Color shapeColor)
{
	f_width = rectWidth;
	f_height = rectHeight;
	this->c_ShapeColor = shapeColor;
	Vector2 sizeVector = Vector2(rectWidth, rectHeight);
	rs_shape.setSize(sizeVector.ToSFMLVector2f());
	rs_shape.setFillColor(shapeColor);
}

void RectRenderer::DrawShape(sf::RenderWindow& window)
{
	rs_shape.setPosition(v2_ShapePosition.ToSFMLVector2f());
	window.draw(rs_shape);
}

void RectRenderer::SetAlpha(float alpha)
{
	c_ShapeColor.a = alpha;
	rs_shape.setFillColor(c_ShapeColor);
}
