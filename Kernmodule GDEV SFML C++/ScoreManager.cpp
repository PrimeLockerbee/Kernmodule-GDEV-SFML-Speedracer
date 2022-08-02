#include "ScoreManager.h"

//Sets the initial score
ScoreManager::ScoreManager()
{
	i_score = 0;
}

ScoreManager& ScoreManager::operator=(const ScoreManager& scoreManager)
{
	i_score = scoreManager.i_score;

	return *this;
}

//Increases the score
void ScoreManager::IncreaseScore(int value)
{
	i_score += value;
}


