#pragma once
#include "Subscriber.hpp"
#include <string>

class Averager: public Subscriber
{
public:
	Averager(const std::string id);
	Subscriber* copy() const override;
	
	int read() const;
};