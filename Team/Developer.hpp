#pragma once
#include <string.h>
#include <iostream>
class TeamLead;
class Developer
{
protected:
	std::string name;
	double salary;
	TeamLead* leader;
public:
	
	Developer(const std::string& name);
	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void setLeader(TeamLead* leader);
	void sendPromotionRequest(double amount);
	void setSalary(double amount);
};

