#include "Request.hpp"
#include <iostream>
#include <string.h>
int Request::counter;
Request::Request(const std::string& message, const std::string& sender) : message(message), sender(sender)
{
	counter++;
	ID = counter;
}

std::string Request::getMessage() const
{
	return message;
}

std::string Request::getSender() const
{
	return sender;
}

int Request::getCount() const
{
	return counter;
}

int Request::getID()const
{
	return ID;
}

void Request::reduceCount()
{
	counter--;
	ID = counter;
}