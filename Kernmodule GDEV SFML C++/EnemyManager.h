#pragma once

#include "Enemy.h"
#include "Player.h"
#include "ScoreManager.h"

class EnemyManager
{
	public:
		std::vector<Enemy> enemies;
		int maxEnemies = 7;

		EnemyManager();
		EnemyManager(int maxEnemies);
		void SpawnEnemy(Vector2 windowSize);
		void RespawnEnemy(Enemy& enemy, Vector2 windowSize);
		void OnUpdate(sf::RenderWindow& window, ScoreManager& scoreManager, Player& player);
	
	private:
		Vector2 GetRandomEnemySpawnPos(Vector2 windowSize);
};
