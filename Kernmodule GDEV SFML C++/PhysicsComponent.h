#pragma once
#include "Vector2.h"

class PhysicsComponent
{
public:
	Vector2 totalForce;		// Total forces in x and y direction in N (newton)
	Vector2 velocity;
	Vector2 acceleration;

	PhysicsComponent();
	PhysicsComponent(float mass);
	PhysicsComponent& operator=(const PhysicsComponent& physicsComponent);
	void addForce(Vector2 forceVector);
	void addFriction();
	void onUpdate();

private:
	float mass;
	float frictionValue = 2;
	//const float gravitationalConstant = 9.81f;
	//const float frictionCoefficient = 0.2f;		// Coefficient value for metal on wood
	const float minVelocity = -20;
	const float maxVelocity = 20;
};
