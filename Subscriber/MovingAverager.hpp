#pragma once
#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>

class MovingAverager: public Subscriber
{
private:
	const size_t windowSize;
	unsigned counter = 0;
public:
	MovingAverager(const std::string id, const size_t windowSize);
	Subscriber* copy() const override;
	size_t getWindow() const;
	void signal(Message) override;
	int read() const;
};