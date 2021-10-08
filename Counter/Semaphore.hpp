#pragma once
#include "LimitedTwowayCounter.hpp"
#include "Counter.hpp"
class Semaphore:public LimitedTwowayCounter
{
public:
	Semaphore();
	Semaphore(bool isIt);
	bool isAvailable();
	void wait();
	void signal();

};

