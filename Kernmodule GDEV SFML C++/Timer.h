#pragma once
#include "Time.h"

class Timer
{
	public:
		Timer();
		Timer(float duration);
		Timer& operator=(const Timer& timer);
		void Reset();
		void Tick();
		float GetTimeLeft();
	
	private:
		float f_timeLeft;
		float f_duration;
};

