#pragma once
#include"Request.hpp"
#include<iostream>
#include <string.h>
class PromotionRequest: public Request
{
protected:
	double amount;
public:
	PromotionRequest(const std::string& sender, double amount);
	double getAmount() const;
};

