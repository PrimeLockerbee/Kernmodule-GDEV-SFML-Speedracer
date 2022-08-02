#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Character.h"
#include "Timer.h"

class Player : public Character
{
	public:
		//Constructors
		Player();
		Player(Vector2 size, sf::Color playerColor);
		Player& operator=(const Player& player);
	
		//Public Methods
		void OnUpdate(sf::RenderWindow& window);
		void Draw(sf::RenderWindow& window);
		void OnCollision();
		int GetLives();
	
	private:
		//Private Variables
		RectangleRenderer rr_RectRenderer;
		int i_horizontalInput;
		int i_lives;
	
		bool b_isInvincible;
		Timer t_InvincibleTimer;

		sf::Texture t_Texture;
		sf::Sprite s_Sprite;

		//Private Methods
		int GetPlayerInput();
		void TickInvincabilityTimer();
		void LoadTexture();
		void InitializeSprite();
};

