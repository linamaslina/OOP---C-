#pragma once
#include "Message.hpp"
#include "Subscriber.hpp"
#include <vector>

class SimplePublisher
{
protected:
	std::vector <Subscriber*> subs;
	std::vector<Message> messages;
public:
	virtual void subscribe(Subscriber*);
	
	void unsubscribe(Subscriber*);
	
	void signal(Message);
};