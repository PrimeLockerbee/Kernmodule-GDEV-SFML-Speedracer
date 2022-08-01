#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "PhysicsComponent.h"
#include "ShapeRenderer.h"
#include "RectRenderer.h"
#include "Math.h"
#include "BoxCollider.h"

class Character
{
	public:
		//Variables
		Vector2 v2_Size;
		Vector2 v2_Position;
		BoxCollider bc_Collider;

		//Methods
		Character();
		Character& operator=(const Character& character);
		void OnUpdate(sf::RenderWindow& window);

	protected:
		Vector2 v2_StartPos;
		PhysicsComponent pc_PhysicsComponent;

		//Private Methods
		Vector2 CalculateNewPosition();
};

