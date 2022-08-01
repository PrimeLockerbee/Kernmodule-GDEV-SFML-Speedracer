#include "BoxCollider.h"

// Constructors //

BoxCollider::BoxCollider()
{
	topY = 0;
	bottomY = 0;
	leftX = 0;
	rightX = 0;
}

BoxCollider::BoxCollider(Vector2 size, Vector2 pos)
{
	this->size = size;
	this->position = pos;
}

BoxCollider& BoxCollider::operator=(const BoxCollider& boxCollider) {
	size = boxCollider.size;
	position = boxCollider.position;

	return *this;
}

// Public Methods //

bool BoxCollider::isCollidingWith(BoxCollider other)
{
	calculateCorners();
	other.calculateCorners();

	// Check collision in Y first, then X.
	if (this->topY < other.bottomY && this->bottomY > other.topY
		&& this->leftX < other.rightX && this->rightX > other.leftX)
	{
		return true;
	}
	return false;
}

// Currently unused: replaced with clamping.
bool BoxCollider::isCollidingWithSideBorders(sf::RenderWindow& window)
{
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

	calculateCorners();
	if (leftX < 0 || rightX > windowSize.x) return true;
	return false;
}

bool BoxCollider::hasPassedBottomBorder(sf::RenderWindow& window)
{
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

	calculateCorners();
	if (topY > windowSize.y) return true;
	return false;
}

void BoxCollider::updatePosition(Vector2 newPos)
{
	position = newPos;
}

void BoxCollider::calculateCorners()
{
	topY = position.y;
	bottomY = position.y + size.y;
	leftX = position.x;
	rightX = position.x + size.x;
}



