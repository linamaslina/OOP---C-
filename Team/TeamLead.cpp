#include "TeamLead.hpp"
#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include"PromotionRequest.hpp"
#include <iostream>
#include <string.h>
#include <vector>

TeamLead::TeamLead(const std::string& name, double salary):Developer(name)
{
	this->leader = this;
	this->salary = salary;
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr)
	{
		developer->setInitialSalary(salary);
		developer->setLeader(leader);
		team.push_back(developer);
	}
}

void  TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	int size = team.size()-1;
	for (int i =size;i>=0;i--)
	{
		if (team[i]->getName() == name)
		{
			team[i]->setLeader(nullptr);
			team.erase(team.begin() + i);
			break;
		}
	}
}
void  TeamLead::increaseTeamSalariesBy(double amount)
{
	int size = team.size();
	double temp = 0.0;
	for (int i = 0; i < size; i++)
	{
		temp = team[i]->getSalary() + amount;
		team[i]->setSalary(temp);
	}
}
void  TeamLead::decreaseTeamSalariesBy(double amount)
{
	int size = team.size();
	double temp = 0.0;
	for (int i = 0; i < size; i++)
	{
		temp = team[i]->getSalary() - amount;
		team[i]->setSalary(temp);
	}
}
void  TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	if (this->leader != nullptr)
	{
		this->leavingRequests.push_back(leavingRequest);
	}

}
void  TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	if (this->leader!=nullptr)
	{
		this->promotionRequests.push_back(promotionRequest);
	}
	
}
void  TeamLead::fulfillLeavingRequests()
{

	int size = leavingRequests.size()-1;
	int size2 = team.size();
	for (int i = size; i >= 0; i--)
	{
		for (int j = 0; j < size2; j++)
		{
			if (team[j]->getName() == leavingRequests[i].getSender())
			{
				std::string temp = leavingRequests[i].getSender();
				leavingRequests[i].reduceCount();
				removeDeveloperFromTeam(temp);
				leavingRequests.pop_back();
			}
		}
	}
	
}
void  TeamLead::fulfillPromotionRequests()
{
	int size = promotionRequests.size()-1;
	int size2 = team.size();
	double temp = 0.0;
	
		for (int i = size; i >= 0; i--)
		{
			for (int j = 0; j < size2; j++)
			{
				if (team[j]->getName() == promotionRequests[i].getSender())
				{
					temp = team[j]->getSalary() + promotionRequests[i].getAmount();
					team[j]->setSalary(temp);
					promotionRequests[i].reduceCount();
					promotionRequests.pop_back();
					break;
				}
			}
		}
	
}
