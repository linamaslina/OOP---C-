#pragma once
#include "SimplePublisher.hpp"
#include <vector>

class BacklogPublisher: public SimplePublisher
{
public:
	void subscribe(Subscriber*) override;
};