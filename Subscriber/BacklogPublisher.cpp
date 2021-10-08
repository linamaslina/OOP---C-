#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* sub)
{
	if (sub != nullptr)
	{
		int size = messages.size();
		for (int i = 0; i < size; i++)
		{
			sub->signal(messages[i]);
		}
		this->subs.push_back(sub);
	}
}
