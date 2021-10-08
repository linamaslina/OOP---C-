#pragma once
#include <iostream>
#include <string.h>
class Request
{
protected:
	std::string message;
	std::string sender;
	unsigned ID;
	static int counter;
public:
	Request(const std::string& message, const std::string& sender);
	std::string getMessage() const;
	std::string getSender() const;
	int getCount() const;
	int getID()const;
	void reduceCount();
};

