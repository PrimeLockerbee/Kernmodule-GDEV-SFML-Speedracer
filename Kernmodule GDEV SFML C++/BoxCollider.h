#pragma once
#include "Vector2.h"

class BoxCollider
{
	public:

		//Constructors
		BoxCollider();
		BoxCollider(Vector2 size, Vector2 pos);
		BoxCollider& operator=(const BoxCollider& boxCollider);

		//Public Methods
		bool IsCollidingWith(BoxCollider collider);
		void UpdatePosition(Vector2 newPos);
		void CalculateCorners();
		bool HasPassedBottomBorder(sf::RenderWindow& window);

	private:
		//Private Variables
		Vector2 v2_Size;
		Vector2 v2_Position;

		float f_bottomY;
		float f_topY;
		float f_leftX;
		float f_rightX;
};

