#pragma once
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"
class LimitedTwowayCounter: virtual public LimitedCounter,virtual public TwowayCounter
{
public:

	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned step);
	
	void decrement();
	int getMin() const;
protected:
	int min;
};

