#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary)
	:Developer(name)
{
	Developer::setInitialSalary(salary);
	Developer::setTeamLead(this);
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return developers;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr) {
		developer->setInitialSalary(salary);
		developer->setTeamLead(this);
		developers.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	for (int i = developers.size() - 1; i >= 0; i--) {
		if (name == developers[i]->getName()) {
			developers[i]->setTeamLead(nullptr);
			developers[i]->decreaseSalary(getSalary());
			developers.erase(developers.begin() + i);
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	int size = developers.size();
	for (int i = 0; i < size; i++) {
		developers[i]->increaseSalary(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	int size = developers.size();
	for (int i = 0; i < size; i++) {
		developers[i]->decreaseSalary(amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	lr.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	pr.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	int size = lr.size();
	for (int i = 0; i < size; i++) {
		std::string temp = lr[i].getSender();
		removeDeveloperFromTeam(temp);
		lr.erase(lr.begin() + i);
	}
}

void TeamLead::fulfillPromotionRequests()
{
	int pr_size = pr.size();
	int dev_size = developers.size();
	for (int i = 0; i < pr_size; i++) {
		for (int j = 0; j < dev_size; j++) {
			if (pr[i].getSender() == developers[j]->getName()) {
				pr.erase(pr.begin() + i);
				developers[j]->increaseSalary(pr[i].getAmount());
			}
		}
	}
}
