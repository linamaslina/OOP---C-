#include "PromotionRequest.hpp"
#include <iostream>
#include <string.h>

PromotionRequest::PromotionRequest(const std::string& sender, double amount) : Request("I want a raise!",sender),amount(amount)
{
}
double PromotionRequest::getAmount() const
{
	return amount;
}