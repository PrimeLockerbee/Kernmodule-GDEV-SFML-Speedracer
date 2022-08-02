#include "Timer.h"

Timer::Timer()
{
	f_duration = 1;
	f_timeLeft = f_duration;
}

Timer::Timer(float duration)
{
	this->f_duration = duration;
	Reset();
}

Timer& Timer::operator=(const Timer& timer)
{
	f_duration = timer.f_duration;
	f_timeLeft = timer.f_timeLeft;

	return *this;
}

//Resets the timer
void Timer::Reset()
{
	f_timeLeft = f_duration;
}

//Timer
void Timer::Tick()
{
	f_timeLeft -= Time::deltaTime;
}

//Returns the time left
float Timer::GetTimeLeft()
{
	return f_timeLeft;
}