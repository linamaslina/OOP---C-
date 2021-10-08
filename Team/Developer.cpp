#include "Developer.hpp"
#include <string.h>
#include <iostream>
#include "TeamLead.hpp"
#include "LeavingRequest.hpp"

Developer::Developer(const std::string& name) : name(name), salary(0.0), leader(nullptr){}

std::string Developer::getName() const
{
	return name;
}

double Developer::getSalary() const
{
	return salary;
}

TeamLead* Developer::getTeamLead() const
{
	return this->leader;
}

void Developer::setInitialSalary(double amount)
{
	if (salary == 0)
	{
		salary = amount;
	}
}

void Developer::sendLeavingRequest()
{
	
	if (leader != nullptr)
	{
		LeavingRequest temp(name);
		leader->addLeavingRequest(temp);
	}
}

void Developer::sendPromotionRequest(double amount)
{
	
	if (leader != nullptr)
	{
		PromotionRequest temp(name, amount);
		leader->addPromotionRequest(temp);
	}
}

void Developer::setLeader(TeamLead* leader)
{
	this->leader = leader;
}

void Developer::setSalary(double amount)
{
	this->salary = amount;
}