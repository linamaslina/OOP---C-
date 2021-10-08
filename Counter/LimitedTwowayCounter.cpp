#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) : min(min), LimitedCounter(max), TwowayCounter(), Counter() {}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial): min(min), Counter(initial), LimitedCounter(max, initial),TwowayCounter(initial,1){}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step): min(min),Counter(initial,step), LimitedCounter(max, initial, step),TwowayCounter(initial, step){}

void LimitedTwowayCounter::decrement()
{
	int temp =step;
	if ((initial-temp )>= min)
	{
		initial -= temp;
	}
}

int LimitedTwowayCounter::getMin() const 
{
	return min;
}