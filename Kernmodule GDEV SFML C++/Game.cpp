#include "Game.h"

Game::Game()
{
	CreateWindow();
	StartGame();
}

Game::~Game()
{
	delete rw_Window;
}

//Private Methods
void Game::CreateWindow()
{
	v2_WindowSize = Vector2(1000, 900);
	rw_Window = new sf::RenderWindow(sf::VideoMode(v2_WindowSize.f_x, v2_WindowSize.f_y), "Avoid the blocks and get a score as high as possible");
	rw_Window->setFramerateLimit(60);
}

//Starts the game
void Game::StartGame()
{
	b_HasEnded = false;
	i_difficulty = 1;
	t_RestartTimer = Timer(cf_restartGameTime);

	p_Player = Player(Vector2(40.0f, 60.0f), sf::Color::Cyan);
	em_EnemyManager = EnemyManager(4);
	sm_ScoreManager = ScoreManager();
}

//Ends the game
void Game::EndGame()
{
	b_HasEnded = true;
	rw_Window->clear();

	DrawGameOverText();
}

void Game::PollEvents()
{
	int horizontalInput = 0;
	sf::Event event;
	while (rw_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			rw_Window->close();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		{
			rw_Window->close();
		}
	}
}

void Game::DrawGameOverText()
{
	um_UIManager.DrawGameOverScreen(*rw_Window, sm_ScoreManager.i_score);
}

//Public Methods
void Game::OnUpdate()
{
	PollEvents();

	if (!b_HasEnded)
	{
		rw_Window->clear();

		p_Player.OnUpdate(*rw_Window);
		em_EnemyManager.OnUpdate(*rw_Window, sm_ScoreManager, p_Player);
		um_UIManager.OnUpdate(*rw_Window, p_Player.GetLives(), sm_ScoreManager.i_score);

		CheckDifficultyIncrease();
		CheckPlayerLives();

		rw_Window->display();
	}
	else
	{
		t_RestartTimer.Tick();
		if (t_RestartTimer.GetTimeLeft() <= 0) {
			StartGame();
		}
	}
}

bool Game::IsRunning()
{
	return rw_Window->isOpen();
}

//Increases the difficulty based on the score
void Game::CheckDifficultyIncrease() 
{
	int difficulty = 1;
	int score = sm_ScoreManager.i_score;

	if (score < 20) 
	{
		difficulty = 1;
	}
	else if (score < 50) 
	{
		difficulty = 2;
	}
	else if (score < 100) 
	{
		difficulty = 3;
	}
	else 
	{
		//Stops increasing the difficulty after a certain point
		for (int i = 1; i <= 25; i++)
		{
			if (score < 150 * i) 
			{
				difficulty = 3 + i;
				break;
			}
		}
	}

	SetDifficulty(difficulty);
}

//Checks if the player i_lives are 0
void Game::CheckPlayerLives()
{
	if (p_Player.GetLives() <= 0) 
	{
		EndGame();
	}
}

void Game::SetDifficulty(int difficulty)
{
	this->i_difficulty = difficulty;
	em_EnemyManager.maxEnemies = difficulty + 2;
}

bool Game::GetHasEnded()
{
	return b_HasEnded;
}

