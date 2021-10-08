#include "Averager.hpp"

Averager::Averager(const std::string ID): Subscriber(ID){}

Subscriber* Averager::copy() const
{
	return new Averager(*this);
}

int Averager::read() const
{
	int size = data.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += data[i];
	}
	if (size != 0)
	{
		return sum / size;
	}
	else return 0;
}