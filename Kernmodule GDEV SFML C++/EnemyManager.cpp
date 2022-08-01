#include "EnemyManager.h"
#include <iostream>

EnemyManager::EnemyManager() {
	maxEnemies = 0;
}

EnemyManager::EnemyManager(int maxEnemies)
{
	this->maxEnemies = maxEnemies;
}

void EnemyManager::SpawnEnemy(Vector2 windowSize)
{
	Vector2 randomPos = getRandomEnemySpawnPos(windowSize);

	Enemy enemy = Enemy(Vector2(100.0f, 100.0f), sf::Color::Red, randomPos);
	enemies.push_back(enemy);
}

void EnemyManager::RespawnEnemy(Enemy& enemy, Vector2 windowSize)
{
	enemy.position = getRandomEnemySpawnPos(windowSize);
}

void EnemyManager::onUpdate(sf::RenderWindow& window, ScoreManager& scoreManager, Player& player)
{
	sf::Vector2u windowSizeSFML = window.getSize();
	Vector2 windowSize = Vector2(windowSizeSFML.x, windowSizeSFML.y);

	// Update each enemy
	for (Enemy& enemy : enemies)
	{
		// Check Bottom Border Collision
		if (enemy.collider.hasPassedBottomBorder(window))
		{
			scoreManager.increaseScore(1);
			RespawnEnemy(enemy, windowSize);
		}

		enemy.onUpdate(window);

		// Check collision with Player
		if (enemy.collider.isCollidingWith(player.collider)) {
			player.onCollision();
		}
	}

	// Spawn a new enemy if there is capacity
	if (enemies.capacity() < maxEnemies) {
		SpawnEnemy(windowSize);
	}
}

Vector2 EnemyManager::getRandomEnemySpawnPos(Vector2 windowSize)
{
	float randomX = Math::randomRange(0, windowSize.x - 100);
	return Vector2(randomX, 0);
}
