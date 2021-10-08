#include "SimplePublisher.hpp"
#include <string>

void SimplePublisher::subscribe(Subscriber* sub)
{
	if (sub != nullptr)
	{
		this->subs.push_back(sub);
	}
}

void SimplePublisher::unsubscribe(Subscriber* sub)
{
	std::string subID =sub->getId();
	int size = subs.size() - 1;
	for (int i = 0; i <= size; i++)
	{
		if (subs[i]->getId() == subID)
		{
			subs.erase(subs.begin() + i);

			break;
		}
	}
}

void SimplePublisher::signal(Message mess)
{
	messages.push_back(mess);
	int size = subs.size();
	for (int i = 0; i < size; i++)
	{
		subs[i]->signal(mess);
	}
}