#include "Subscriber.hpp"
#include <string>

Subscriber::Subscriber(const std::string id) : id(id)
{}

std::string Subscriber::getId() const
{
	return id;
}

void Subscriber::signal(Message mess)
{
	data.push_back(mess.getData());
}