#include "BoxCollider.h"

//Box collider coordinates
BoxCollider::BoxCollider()
{
	f_topY = 0;
	f_bottomY = 0;
	f_leftX = 0;
	f_rightX = 0;
}

//Size and position of the box collider
BoxCollider::BoxCollider(Vector2 size, Vector2 pos)
{
	this->v2_Size = size;
	this->v2_Position = pos;
}

BoxCollider& BoxCollider::operator=(const BoxCollider& boxCollider) {
	v2_Size = boxCollider.v2_Size;
	v2_Position = boxCollider.v2_Position;

	return * this;
}

void BoxCollider::UpdatePosition(Vector2 newPos)
{
	v2_Position = newPos;
}

//Checks if the box collider collides with anything
bool BoxCollider::IsCollidingWith(BoxCollider other)
{
	CalculateCorners();
	other.CalculateCorners();

	if (this->f_topY < other.f_bottomY && this->f_bottomY > other.f_topY && this->f_leftX < other.f_rightX && this->f_rightX > other.f_leftX)
	{
		return true;
	}
	return false;
}

//Calculates the corners of the box colliders
void BoxCollider::CalculateCorners()
{
	f_topY = v2_Position.f_y;
	f_bottomY = v2_Position.f_y + v2_Size.f_y;
	f_leftX = v2_Position.f_x;
	f_rightX = v2_Position.f_x + v2_Size.f_x;
}

//Checks if the box collider has passed outside of the window
bool BoxCollider::HasPassedBottomBorder(sf::RenderWindow& window)
{
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

	CalculateCorners();
	if (f_topY > windowSize.f_y)
	{
		return true;
	}
	return false;
}




