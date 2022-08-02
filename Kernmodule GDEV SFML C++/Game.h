#pragma once

#include "EnemyManager.h"
#include "ScoreManager.h"
#include "UIManager.h"
#include "Player.h"
#include "Timer.h"
#include "Vector2.h"

class Game
{
	public:
		//Public Variables
		Game();
		virtual ~Game();
			
		//Public Methods
		void OnUpdate();
		bool IsRunning();

		void CheckDifficultyIncrease();
		void CheckPlayerLives();
		void SetDifficulty(int difficulty);
		bool GetHasEnded();
			
	private:
		//Private Variables
		Player p_Player;
		EnemyManager em_EnemyManager;
		ScoreManager sm_ScoreManager;
		UIManager um_UIManager;

		bool b_HasEnded;
		int i_difficulty;
		const float cf_restartGameTime = 7.0f;
		Timer t_RestartTimer;
	
		Vector2 v2_WindowSize;
		sf::RenderWindow* rw_Window;
	
		//Private Methods
		void CreateWindow();
		void StartGame();
		void EndGame();
		void PollEvents();
		void DrawGameOverText();

};

