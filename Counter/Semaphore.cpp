#include "Semaphore.hpp"

Semaphore::Semaphore(): Counter(), LimitedCounter(1),TwowayCounter(),LimitedTwowayCounter(0,1)
{}

Semaphore::Semaphore(bool isIt): Counter(), LimitedCounter(1), TwowayCounter(), LimitedTwowayCounter(0, 1)
{
	if (isIt == true)
	{
		initial = 1;
	}
	else initial = 0;
}

bool Semaphore::isAvailable()
{
	return getTotal() > 0;
}

void Semaphore::wait()
{
	decrement();
}

void Semaphore::signal()
{
	increment();
}