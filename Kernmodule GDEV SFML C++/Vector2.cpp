#include <iostream>
#include "Vector2.h"

//Vector2 X and Y
Vector2::Vector2() 
{
	f_x = 0;
	f_y = 0;
}

//Vector2 X and Y
Vector2::Vector2(float x, float y)
{
	this->f_x = x;
	this->f_y = y;
}

Vector2& Vector2::operator=(const Vector2& v)
{
	f_x = v.f_x;
	f_y = v.f_y;
	return *this;
}

//Vector2 addition
Vector2 Vector2::operator+(Vector2 otherVector)
{
	return Vector2(f_x + otherVector.f_x, f_y + otherVector.f_y);
}

//Vector2 substraction
Vector2 Vector2::operator-(Vector2 otherVector)
{
	return Vector2(f_x - otherVector.f_x, f_y - otherVector.f_y);
}

//Vector2 multiplication
Vector2 Vector2::operator*(float scalar)
{
	return Vector2(f_x * scalar, f_y * scalar);
}

//Vector2 dividation
Vector2 Vector2::operator/(float scalar)
{
	if (scalar == 0)
	{
		std::cout << "Dividing by 0 not allowed, operation ignored" << std::endl;
		return Vector2(f_x, f_y);
	}
	else
	{
		return Vector2(f_x / scalar, f_y / scalar);
	}
}

//Public Methods
sf::Vector2f Vector2::ToSFMLVector2f()
{
	return sf::Vector2f(f_x, f_y);
}

sf::Vector2i Vector2::ToSFMLVector2i()
{
	return sf::Vector2i(f_x, f_y);
}

std::string Vector2::to_string() 
{
	return "x: " + std::to_string(f_x) + " y: " + std::to_string(f_y);
}

