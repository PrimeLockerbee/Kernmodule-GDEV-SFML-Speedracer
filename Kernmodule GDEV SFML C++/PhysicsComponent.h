#pragma once
#include "Vector2.h"

class PhysicsComponent
{
	public:
		//Total force in directions x and y in newtons (N)
		Vector2 v2_TotalForce;		
		Vector2 v2_Velocity;
		Vector2 v2_Acceleration;
	
		PhysicsComponent();
		PhysicsComponent(float mass);
		PhysicsComponent& operator=(const PhysicsComponent& physicsComponent);
		void AddForce(Vector2 forceVector);
		void AddFriction();
		void OnUpdate();
	
	private:
		float f_mass;
		float f_frictionValue = 2;
		const float f_minVelocity = -20;
		const float f_maxVelocity = 20;
};



