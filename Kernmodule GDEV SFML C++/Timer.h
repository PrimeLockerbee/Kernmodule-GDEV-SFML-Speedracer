#pragma once
#include "Time.h"

class Timer
{
public:
	Timer();
	Timer(float duration);
	Timer& operator=(const Timer& timer);
	void reset();
	void tick();
	float getTimeLeft();

private:
	float timeLeft;
	float duration;
};

