#include "PhysicsComponent.h"
#include "Math.h"

PhysicsComponent::PhysicsComponent()
{
	f_mass = 1;
	v2_TotalForce = Vector2();
}

PhysicsComponent::PhysicsComponent(float mass)
{
	this->f_mass = mass;
	v2_TotalForce = Vector2();
}

PhysicsComponent& PhysicsComponent::operator=(const PhysicsComponent& physicsComponent)
{
	f_mass = physicsComponent.f_mass;
	f_frictionValue = physicsComponent.f_frictionValue;
	v2_Velocity = physicsComponent.v2_Velocity;
	v2_Acceleration = physicsComponent.v2_Acceleration;
	v2_TotalForce = physicsComponent.v2_TotalForce;

	return *this;
}

//Adds force
void PhysicsComponent::AddForce(Vector2 forceVector)
{
	v2_TotalForce = v2_TotalForce + forceVector;
}

//Adds friction
void PhysicsComponent::AddFriction()
{
	Vector2 frictionVector = Vector2(f_frictionValue, f_frictionValue);

	if (v2_TotalForce.f_x > 0 || v2_Velocity.f_x > 0)
	{
		v2_TotalForce.f_x -= frictionVector.f_x;
	}
	else if (v2_TotalForce.f_x < 0 || v2_Velocity.f_x < 0)
	{
		v2_TotalForce.f_x += frictionVector.f_x;
	}

	if (v2_TotalForce.f_y > 0 || v2_Velocity.f_y > 0)
	{
		v2_TotalForce.f_y -= frictionVector.f_y;
	}
	else if (v2_TotalForce.f_y < 0 || v2_Velocity.f_y < 0)
	{
		v2_TotalForce.f_y += frictionVector.f_y;
	}
}

void PhysicsComponent::OnUpdate()
{
	AddFriction();

	//Calculates the acceleration for this frame
	v2_Acceleration = v2_TotalForce / f_mass;	

	if (v2_Velocity.f_x > 0)
	{
		v2_Velocity.f_x = Math::Clamp(v2_Velocity.f_x + v2_Acceleration.f_x, 0, f_maxVelocity);
	}
	else if (v2_Velocity.f_x < 0)
	{
		v2_Velocity.f_x = Math::Clamp(v2_Velocity.f_x + v2_Acceleration.f_x, f_minVelocity, 0);
	}
	else {
		v2_Velocity.f_x += v2_Acceleration.f_x;
	}

	if (v2_Velocity.f_y > 0)
	{
		v2_Velocity.f_y = Math::Clamp(v2_Velocity.f_y + v2_Acceleration.f_y, 0, f_maxVelocity);
	}
	else if (v2_Velocity.f_y < 0)
	{
		v2_Velocity.f_y = Math::Clamp(v2_Velocity.f_y + v2_Acceleration.f_y, f_minVelocity, 0);
	}
	else
	{
		v2_Velocity.f_y += v2_Acceleration.f_y;
	}

	//Resets the force for the next frame
	v2_TotalForce = Vector2(0, 0);
}
