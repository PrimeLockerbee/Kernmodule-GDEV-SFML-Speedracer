#include "UIManager.h"
#include <iostream>;

UIManager::UIManager()
{
	LoadFont();
	InitializeTexts();
}

void UIManager::OnUpdate(sf::RenderWindow& window, int playerLives, int score)
{
	t_ScoreText.setString(std::to_string(score));
	window.draw(t_ScoreText);

	t_PlayerLivesText.setString("Lives: " + std::to_string(playerLives));
	window.draw(t_PlayerLivesText);
}

void UIManager::DrawGameOverScreen(sf::RenderWindow& window, int score)
{
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

	t_GameOverText.setString("You have lost! \nScore: " + std::to_string(score));

	// Set the text to the middle of the screen
	float textWidth = t_GameOverText.getLocalBounds().width;
	float textHeight = t_GameOverText.getLocalBounds().height;
	float textX = (windowSize.f_x - textWidth) / 2;
	float textY = (windowSize.f_y - textHeight) / 2;
	t_GameOverText.setPosition(textX, textY);

	window.draw(t_GameOverText);
}

void UIManager::LoadFont()
{
	f_Font.loadFromFile("Resources/Roboto-Black.ttf");
}

void UIManager::InitializeTexts()
{
	// ScoreText
	t_ScoreText.setFont(f_Font);
	t_ScoreText.setPosition(450.0f, 100.0f);
	t_ScoreText.setString("0");
	t_ScoreText.setCharacterSize(100);
	t_ScoreText.setStyle(sf::Text::Bold);

	// Game Over Text
	t_GameOverText.setFont(f_Font);
	t_GameOverText.setCharacterSize(50);

	t_PlayerLivesText.setFont(f_Font);
	t_PlayerLivesText.setCharacterSize(40);
	t_PlayerLivesText.setPosition(10.0f, 10.0f);
	t_PlayerLivesText.setString("Lives: ");
}
