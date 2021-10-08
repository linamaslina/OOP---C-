#pragma once
#include "Counter.hpp"

class TwowayCounter:virtual public Counter
{
public:
	TwowayCounter();
	TwowayCounter(int initial, unsigned step);
	void decrement();
};

