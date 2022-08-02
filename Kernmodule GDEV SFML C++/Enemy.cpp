#include <iostream>
#include "Enemy.h"

//The enemy itself
Enemy::Enemy(Vector2 size, sf::Color enemyColor, Vector2 v2_StartPos)
{
	this->v2_Size = size;
	v2_Position = v2_StartPos;

	b_IsAccelerating = true;
	t_AcceleratingTimer = Timer(Math::RandomRange(1.0f, 1.5f));
	t_BrakingTimer = Timer(.50f);
	v2_DownwardForce = Vector2(0, Math::RandomRange(2.5f, 3.5f));

	bc_Collider = BoxCollider(size, v2_Position);
	rr_RectRenderer = RectangleRenderer(size.f_x, size.f_y, enemyColor);
	pc_PhysicsComponent = PhysicsComponent(Math::RandomRange(10, 15));
}

void Enemy::OnUpdate(sf::RenderWindow& window)
{
	TickTimers();
	if (b_IsAccelerating)
	{
		pc_PhysicsComponent.AddForce(v2_DownwardForce);
	}
	Character::OnUpdate(window);
	rr_RectRenderer.SetShapePosition(v2_Position);

	Draw(window);
}

//Returns true if the enemy is outsde the windowheight
bool Enemy::IsOutOfScreen(sf::RenderWindow& window)
{
	float windowHeight = window.getSize().y;
	if (v2_Position.f_y > windowHeight)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//Draws the enemy
void Enemy::Draw(sf::RenderWindow& window)
{
	rr_RectRenderer.DrawShape(window);
}

//Switch between accelerating and braking
void Enemy::TickTimers()
{
	if (b_IsAccelerating) 
	{
		t_AcceleratingTimer.Tick();

		if (t_AcceleratingTimer.GetTimeLeft() <= 0) 
		{
			BrakingSwitch();
		}
	}
	else 
	{
		t_BrakingTimer.Tick();

		if (t_BrakingTimer.GetTimeLeft() <= 0) 
		{
			AccelerationSwitch();
		}
	}
}

//Switches to accelerating 
void Enemy::AccelerationSwitch()
{
	v2_DownwardForce = Vector2(0, Math::RandomRange(2.5f, 3.5f));
	t_AcceleratingTimer = Timer(Math::RandomRange(1.0f, 1.5f));

	t_BrakingTimer.Reset();
	b_IsAccelerating = true;
}

//Switches to braking
void Enemy::BrakingSwitch()
{
	t_AcceleratingTimer.Reset();
	b_IsAccelerating = false;

	Vector2 sidewaysForce = Vector2(70 * Math::RandomGetSign(), 0);

	pc_PhysicsComponent.AddForce(sidewaysForce);
}
