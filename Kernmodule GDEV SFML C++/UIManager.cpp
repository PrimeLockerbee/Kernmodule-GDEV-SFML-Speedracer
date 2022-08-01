#include "UIManager.h"
#include <iostream>;

UIManager::UIManager()
{
	loadFont();
	initializeTexts();
}

void UIManager::onUpdate(sf::RenderWindow& window, int playerLives, int score)
{
	scoreText.setString(std::to_string(score));
	window.draw(scoreText);

	playerLivesText.setString("Lives: " + std::to_string(playerLives));
	window.draw(playerLivesText);
}

void UIManager::drawGameOverScreen(sf::RenderWindow& window, int score)
{
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

	gameOverText.setString("Game over! \nScore: " + std::to_string(score));

	// Set the text to the middle of the screen
	float textWidth = gameOverText.getLocalBounds().width;
	float textHeight = gameOverText.getLocalBounds().height;
	float textX = (windowSize.x - textWidth) / 2;
	float textY = (windowSize.y - textHeight) / 2;
	gameOverText.setPosition(textX, textY);

	window.draw(gameOverText);
}

void UIManager::loadFont()
{
	font.loadFromFile("Resources/Roboto-Black.ttf");
}

void UIManager::initializeTexts()
{
	// ScoreText
	scoreText.setFont(font);
	scoreText.setPosition(450.0f, 100.0f);
	scoreText.setString("0");
	scoreText.setCharacterSize(100);
	scoreText.setStyle(sf::Text::Bold);

	// Game Over Text
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(50);

	playerLivesText.setFont(font);
	playerLivesText.setCharacterSize(40);
	playerLivesText.setPosition(10.0f, 10.0f);
	playerLivesText.setString("Lives: ");
}
