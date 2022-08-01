#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
	i_score = 0;
}

ScoreManager& ScoreManager::operator=(const ScoreManager& scoreManager)
{
	i_score = scoreManager.i_score;

	return *this;
}

void ScoreManager::IncreaseScore(int value)
{
	i_score += value;
}


