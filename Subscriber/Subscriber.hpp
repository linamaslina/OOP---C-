#pragma once
#include "Message.hpp"
#include <string>
#include <vector>

class Subscriber
{
protected:
	std::vector<int> data;
public:
	const std::string id;
	Subscriber(const std::string id);

	virtual Subscriber* copy() const = 0;

	virtual ~Subscriber() = default;

	std::string getId() const;

	virtual void signal(Message);

	virtual int read()const =0;
};

