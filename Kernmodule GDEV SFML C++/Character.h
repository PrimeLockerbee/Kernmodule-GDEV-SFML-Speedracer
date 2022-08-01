#pragma once

#include "Vector2.h"
#include "PhysicsComponent.h"
#include "ShapeRenderer.h"
#include "RectRenderer.h"
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "BoxCollider.h"

class Character
{
public:
	// Variables
	Vector2 size;
	Vector2 position;
	BoxCollider collider;

	// Methods
	Character();
	Character& operator=(const Character& character);
	void onUpdate(sf::RenderWindow& window);

protected:
	Vector2 startPos;
	PhysicsComponent physicsComponent;

	// Private Methods //
	Vector2 calculateNewPosition();
	void onSideBorderCollision();
};

