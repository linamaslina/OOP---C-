#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string id, const size_t period) : Subscriber(id), period(period)
{}

Subscriber* PeriodicSampler::copy() const
{
	return new PeriodicSampler(*this);
}

size_t PeriodicSampler::getperiod() const
{
	return period;
}

void PeriodicSampler::signal(Message mess)
{

	if (counter == 0)
	{
		data.push_back(mess.getData());
		counter++;
	}
	else if (counter == period)
	{
		data.push_back(mess.getData());
		counter = 0;
	}
	else counter++;
}

int PeriodicSampler::read() const
{

	int size = data.size();
	std::vector<int> temp;
	if (size == 0)
	{
		return 0;
	}
	else if (size == 1)
	{
		return data[0];
	}
	else return data[data.size() - 1];
	
}