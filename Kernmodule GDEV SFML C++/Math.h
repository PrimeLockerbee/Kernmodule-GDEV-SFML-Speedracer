#pragma once
class Math
{
	public:
		static float Abs(float value);
		static float Clamp(float value, float minValue, float maxValue);
		static float RandomRange(float min, float max);
		static int RandomGetSign();
};

