#include <iostream>
#include "EnemyManager.h"

EnemyManager::EnemyManager() 
{
	maxEnemies = 0;
}

EnemyManager::EnemyManager(int maxEnemies)
{
	this->maxEnemies = maxEnemies;
}

//Spawns the enemy
void EnemyManager::SpawnEnemy(Vector2 windowSize)
{
	Vector2 randomPos = GetRandomEnemySpawnPos(windowSize);

	Enemy enemy = Enemy(Vector2(100.0f, 100.0f), sf::Color::Red, randomPos);
	enemies.push_back(enemy);
}

//Respawns the enemy
void EnemyManager::RespawnEnemy(Enemy& enemy, Vector2 windowSize)
{
	enemy.v2_Position = GetRandomEnemySpawnPos(windowSize);
}

void EnemyManager::OnUpdate(sf::RenderWindow& window, ScoreManager& scoreManager, Player& player)
{
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

	for (Enemy& enemy : enemies)
	{
		//Adds 1 to the score and respawns the enemy
		if (enemy.bc_Collider.HasPassedBottomBorder(window))
		{
			scoreManager.IncreaseScore(1);
			RespawnEnemy(enemy, windowSize);
		}

		enemy.OnUpdate(window);

		//Checks if the enemy collides with the player
		if (enemy.bc_Collider.IsCollidingWith(player.bc_Collider))
		{
			player.OnCollision();
		}
	}

	//Spawns an enemy if the max hasn't been reached
	if (enemies.capacity() < maxEnemies) 
	{
		SpawnEnemy(windowSize);
	}
}

//Gets a random spawn position on the x-axis on y = 0
Vector2 EnemyManager::GetRandomEnemySpawnPos(Vector2 windowSize)
{
	float randomX = Math::RandomRange(0, windowSize.f_x - 100);
	return Vector2(randomX, 0);
}
