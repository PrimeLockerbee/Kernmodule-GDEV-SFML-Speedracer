#pragma once

#include <SFML/Graphics.hpp>

class Vector2
{
	public:
		// Public Variables
		float f_x;
		float f_y;
			
		// Constructors
		Vector2();
		Vector2(float x, float y);

		// Operators
		Vector2& operator=(const Vector2& v);
		Vector2 operator+(Vector2 otherVector);
		Vector2 operator-(Vector2 otherVector);
		Vector2 operator*(float scalar);
		Vector2 operator/(float scalar);
	
		// Public Methods
		sf::Vector2f ToSFMLVector2f();	
		sf::Vector2i ToSFMLVector2i();
		std::string to_string();
};

