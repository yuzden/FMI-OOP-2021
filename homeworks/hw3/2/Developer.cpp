#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string& name)
	:name(name), salary(0), teamLead(nullptr)
{
}


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
	return teamLead;
}

void Developer::setInitialSalary(double amount)
{
	if (salary == 0) {
		salary = amount;
	}
}

void Developer::setTeamLead(TeamLead* tl)
{
	teamLead = tl;
}

void Developer::sendLeavingRequest()
{
	if (teamLead != nullptr) {
		LeavingRequest temp = LeavingRequest(name);
		teamLead->addLeavingRequest(temp);
	}
}

void Developer::sendPromotionRequest(double amount)
{
	if (teamLead != nullptr) {
		PromotionRequest temp = PromotionRequest(name, amount);
		teamLead->addPromotionRequest(temp);

	}
}

void Developer::increaseSalary(double amount)
{
	salary += amount;
}

void Developer::decreaseSalary(double amount)
{
	salary -= amount;
}
