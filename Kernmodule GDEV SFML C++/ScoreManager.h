#pragma once

#include <SFML/Graphics.hpp>

class ScoreManager
{
public:
	int score;

	ScoreManager();
	ScoreManager& operator=(const ScoreManager& scoreManager);
	void increaseScore(int value);
};

