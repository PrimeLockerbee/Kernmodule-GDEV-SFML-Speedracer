#include "PhysicsComponent.h"
#include "Math.h"

PhysicsComponent::PhysicsComponent()
{
	mass = 1;
	totalForce = Vector2();
}

PhysicsComponent::PhysicsComponent(float mass)
{
	this->mass = mass;
	totalForce = Vector2();
}

PhysicsComponent& PhysicsComponent::operator=(const PhysicsComponent& physicsComponent)
{
	mass = physicsComponent.mass;
	frictionValue = physicsComponent.frictionValue;
	velocity = physicsComponent.velocity;
	acceleration = physicsComponent.acceleration;
	totalForce = physicsComponent.totalForce;

	return *this;
}

void PhysicsComponent::addForce(Vector2 forceVector)
{
	totalForce = totalForce + forceVector;
}

void PhysicsComponent::addFriction()
{
	Vector2 frictionVector = Vector2(frictionValue, frictionValue);

	if (totalForce.x > 0 || velocity.x > 0)
	{
		totalForce.x -= frictionVector.x;
	}
	else if (totalForce.x < 0 || velocity.x < 0)
	{
		totalForce.x += frictionVector.x;
	}

	if (totalForce.y > 0 || velocity.y > 0)
	{
		totalForce.y -= frictionVector.y;

	}
	else if (totalForce.y < 0 || velocity.y < 0)
	{
		totalForce.y += frictionVector.y;
	}
}

void PhysicsComponent::onUpdate()
{
	addFriction();
	acceleration = totalForce / mass;	// Calculate the acceleration for this frame.

	if (velocity.x > 0)
	{
		velocity.x = Math::Clamp(velocity.x + acceleration.x, 0, maxVelocity);
	}
	else if (velocity.x < 0)
	{
		velocity.x = Math::Clamp(velocity.x + acceleration.x, minVelocity, 0);
	}
	else {
		velocity.x += acceleration.x;
	}

	if (velocity.y > 0)
	{
		velocity.y = Math::Clamp(velocity.y + acceleration.y, 0, maxVelocity);
	}
	else if (velocity.y < 0)
	{
		velocity.y = Math::Clamp(velocity.y + acceleration.y, minVelocity, 0);
	}
	else
	{
		velocity.y += acceleration.y;
	}

	totalForce = Vector2(0, 0);	// Reset the total force for the next frame
}
