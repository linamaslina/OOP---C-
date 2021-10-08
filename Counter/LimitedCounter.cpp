#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max):max(max), Counter(){}

LimitedCounter::LimitedCounter(int max, int initial): max(max),Counter(initial){}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step): max(max), Counter(initial, step){}

void LimitedCounter::increment()
{
	int temp = step;
	if ((initial+temp )<= max)
	{
		initial += temp;
	}
}

int LimitedCounter::getMax() const
{
	return max;
}