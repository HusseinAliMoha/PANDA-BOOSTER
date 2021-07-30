#pragma once
#include <cfenv>
#include <cmath>

class BankersRounding
{
public:
	static double round(double value)
	{
		int currentRoundingMode = std::fegetround();
		std::fesetround(FE_TONEAREST);
		double returnValue = std::rint(value);
		std::fesetround(currentRoundingMode);
		return returnValue;
	}
};
