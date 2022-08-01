#pragma once
#include "ShapeRenderer.h"

class RectRenderer : public ShapeRenderer
{
	public:
		float f_width;
		float f_height;

		RectRenderer();
		RectRenderer(float rectWidth, float rectHeight, sf::Color shapeColor);
		void DrawShape(sf::RenderWindow& window);
		void SetAlpha(float alpha);
	
	private:
		sf::RectangleShape rs_shape;
};

