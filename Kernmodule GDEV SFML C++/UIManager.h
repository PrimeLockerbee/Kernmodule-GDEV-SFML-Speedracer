#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class UIManager
{
	public:
		UIManager();
		void OnUpdate(sf::RenderWindow& window, int playerLives, int score);
		void DrawGameOverScreen(sf::RenderWindow& window, int score);
			
	private:
		sf::Font f_Font;
		sf::Text t_ScoreText;
		sf::Text t_GameOverText;
		sf::Text t_PlayerLivesText;

		void LoadFont();
		void InitializeTexts();
};

