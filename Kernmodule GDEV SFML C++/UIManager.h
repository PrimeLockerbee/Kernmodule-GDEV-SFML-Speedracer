#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class UIManager
{
public:
	UIManager();
	void onUpdate(sf::RenderWindow& window, int playerLives, int score);
	void drawGameOverScreen(sf::RenderWindow& window, int score);

private:
	sf::Font font;
	sf::Text scoreText;
	sf::Text gameOverText;
	sf::Text playerLivesText;

	void loadFont();
	void initializeTexts();
};

