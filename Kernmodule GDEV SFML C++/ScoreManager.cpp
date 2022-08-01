#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
	score = 0;
}

ScoreManager& ScoreManager::operator=(const ScoreManager& scoreManager)
{
	score = scoreManager.score;

	return *this;
}

void ScoreManager::increaseScore(int value)
{
	score += value;
}


