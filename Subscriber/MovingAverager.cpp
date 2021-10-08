#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string id, const size_t windowSize): Subscriber(id), windowSize(windowSize){}

Subscriber* MovingAverager::copy() const
{
	return new MovingAverager(*this);
}

size_t MovingAverager::getWindow() const
{
	return windowSize;
}

void MovingAverager::signal(Message mess)
{

	if (counter < windowSize)
	{
		data.push_back(mess.getData());
		counter++;
	}
	else
	{
		data.erase(data.begin());
		data.push_back(mess.getData());
	}
}

int MovingAverager::read() const
{

	int size = data.size()-1;
	int tempwindow = windowSize - 1;
	int sum = 0;
	if (size==-1 || tempwindow == -1)
	{
		return 0;
	}
	else if (tempwindow >= size && size !=-1)
	{
		for (int i = 0; i <= size; i++)
		{
			sum += data[i];
		}
		return int(sum / data.size());
	}

	
	else return 0;
}