#pragma once
#include <string>

#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead;

class Developer {
public:
	Developer(const std::string& name);
	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	void setInitialSalary(double amount);
	void setTeamLead(TeamLead* tl);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);

	void increaseSalary(double amount);
	void decreaseSalary(double amount);
private:
	std::string name;
	double salary;
	TeamLead* teamLead;
};