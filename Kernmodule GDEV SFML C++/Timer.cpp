#include "Timer.h"

Timer::Timer()
{
	duration = 1;
	timeLeft = duration;
}

Timer::Timer(float duration)
{
	this->duration = duration;
	reset();
}

Timer& Timer::operator=(const Timer& timer)
{
	duration = timer.duration;
	timeLeft = timer.timeLeft;

	return *this;
}

void Timer::reset()
{
	timeLeft = duration;
}

void Timer::tick()
{
	timeLeft -= Time::deltaTime;
}

float Timer::getTimeLeft()
{
	return timeLeft;
}