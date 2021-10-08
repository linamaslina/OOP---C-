#pragma once
#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>

class PeriodicSampler: public Subscriber
{
private:
	const size_t period;
	unsigned counter = 0;
public:
	PeriodicSampler(const std::string id, const size_t period);
	Subscriber* copy() const override;
	size_t getperiod() const;
	void signal(Message) override;
	int read() const;
};