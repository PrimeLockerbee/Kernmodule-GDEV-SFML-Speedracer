#pragma once
class Math
{
	public:
		static float Clamp(float value, float minValue, float maxValue);
		static float RandomRange(float min, float max);
		static int RandomGetSign();
};

