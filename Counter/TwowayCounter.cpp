#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter(): Counter(){}

TwowayCounter::TwowayCounter(int initial, unsigned step): Counter(initial, step){}

void TwowayCounter::decrement()
{
	initial -= step;
}