#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Vector2 size, sf::Color enemyColor, Vector2 startPos)
{
	this->size = size;
	position = startPos;

	isAccelerating = true;
	acceleratingTimer = Timer(Math::randomRange(1.0f, 1.5f));
	brakingTimer = Timer(.50f);
	downwardForce = Vector2(0, Math::randomRange(2.5f, 3.5f));

	collider = BoxCollider(size, position);
	rectRenderer = RectRenderer(size.x, size.y, enemyColor);
	physicsComponent = PhysicsComponent(Math::randomRange(10, 15));
}

void Enemy::onUpdate(sf::RenderWindow& window)
{
	tickTimers();
	if (isAccelerating)
	{
		physicsComponent.addForce(downwardForce);
	}
	Character::onUpdate(window);
	rectRenderer.SetShapePosition(position);


	draw(window);
}

bool Enemy::isOutOfScreen(sf::RenderWindow& window)
{
	float windowHeight = window.getSize().y;
	if (position.y > windowHeight)
	{
		return true;
	}
	else {
		return false;
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	rectRenderer.drawShape(window);
}

void Enemy::tickTimers()
{
	if (isAccelerating) {
		acceleratingTimer.tick();
		if (acceleratingTimer.getTimeLeft() <= 0) {
			switchToBraking();
		}
	}
	else {
		brakingTimer.tick();
		if (brakingTimer.getTimeLeft() <= 0) {
			switchToAccelerating();
		}
	}
}

void Enemy::switchToAccelerating()
{
	// Give the enemy a new downforce an accelerating Timer to randomize its movement
	downwardForce = Vector2(0, Math::randomRange(2.5f, 3.5f));
	acceleratingTimer = Timer(Math::randomRange(1.0f, 1.5f));

	brakingTimer.reset();
	isAccelerating = true;
}

void Enemy::switchToBraking()
{
	acceleratingTimer.reset();
	isAccelerating = false;

	Vector2 sidewaysForce = Vector2(75 * Math::getRandomSign(), 0);
	physicsComponent.addForce(sidewaysForce);		// Add a sideways force for 1 frame
}
