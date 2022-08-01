#pragma once
#include "Character.h";
#include "Timer.h";

class Enemy : public Character
{
	public:
		Enemy(Vector2 size, sf::Color playerColor, Vector2 v2_StartPos);

		virtual void OnUpdate(sf::RenderWindow& window);
		bool IsOutOfScreen(sf::RenderWindow& window);
		virtual void Draw(sf::RenderWindow& window);

	private:
		RectRenderer rr_RectRenderer;
		Vector2 v2_DownwardForce;
		Timer t_AcceleratingTimer;
		Timer t_BrakingTimer;
		bool b_IsAccelerating;
	
		void TickTimers();
		void AccelerationSwitch();
		void BrakingSwitch();
};


