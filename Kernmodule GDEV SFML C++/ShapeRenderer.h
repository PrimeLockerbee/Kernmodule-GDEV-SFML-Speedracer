#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class ShapeRenderer
{
	public:
		Vector2 v2_ShapePosition;
		sf::Color c_ShapeColor;
			
		void SetShapePosition(Vector2 pos);
		virtual void DrawShape(sf::RenderWindow& window) = 0;
};

