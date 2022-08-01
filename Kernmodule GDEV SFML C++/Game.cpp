#include "Game.h"

Game::Game()
{
	createWindow();
	startGame();
}

Game::~Game()
{
	delete window;
}

// Private Methods //
void Game::createWindow()
{
	windowSize = Vector2(1000, 900);
	window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Avoid the cubes");
	window->setFramerateLimit(60);
}

void Game::startGame()
{
	hasEnded = false;
	difficulty = 1;
	restartTimer = Timer(restartGameTime);

	player = Player(Vector2(35.0f, 50.0f), sf::Color::Green);
	enemyManager = EnemyManager(3);
	scoreManager = ScoreManager();
	// UIManager uses default constructor and doesn't need to be replaced when restarting game.
}

void Game::endGame()
{
	hasEnded = true;
	window->clear();

	drawGameOverText();
}

void Game::pollEvents()
{
	int horizontalInput = 0;
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window->close();
		}
	}
}

void Game::drawGameOverText()
{
	uiManager.drawGameOverScreen(*window, scoreManager.score);
}

// Public Methods //
void Game::onUpdate()
{
	pollEvents();

	if (!hasEnded)
	{
		window->clear();

		player.onUpdate(*window);
		enemyManager.onUpdate(*window, scoreManager, player);
		uiManager.onUpdate(*window, player.getLives(), scoreManager.score);
		// I wanted to trigger this function in the scoreManager whenever increaseScore was called.
		// I don't know how to efficiently call upon the Game class function, referencing the game object was very messy.
		checkDifficultyIncrease();
		checkPlayerLives();

		window->display();
	}
	else
	{
		restartTimer.tick();
		if (restartTimer.getTimeLeft() <= 0) {
			startGame();
		}
	}
}

bool Game::isRunning()
{
	return window->isOpen();
}

void Game::checkDifficultyIncrease() {

	int difficulty = 1;
	int score = scoreManager.score;

	if (score < 20) {
		difficulty = 1;
	}
	else if (score < 50) {
		difficulty = 2;
	}
	else if (score < 100) {
		difficulty = 3;
	}
	else {
		// After a certain point, increase the difficulty every 150 points
		// After a score of 7500 the difficulty finally stops increasing
		for (int i = 1; i <= 50; i++)
		{
			if (score < 150 * i) {
				difficulty = 3 + i;
				break;
			}
		}
	}
	setDifficulty(difficulty);
}

void Game::checkPlayerLives()
{
	if (player.getLives() <= 0) {
		endGame();
	}
}

void Game::setDifficulty(int difficulty)
{
	this->difficulty = difficulty;
	enemyManager.maxEnemies = difficulty + 2;
}

bool Game::getHasEnded()
{
	return hasEnded;
}

