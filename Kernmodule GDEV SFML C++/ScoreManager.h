#pragma once

#include <SFML/Graphics.hpp>

class ScoreManager
{
public:
	int i_score;

	ScoreManager();
	ScoreManager& operator=(const ScoreManager& scoreManager);
	void IncreaseScore(int value);
};

