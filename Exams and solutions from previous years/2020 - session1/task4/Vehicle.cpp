#include "Vehicle.hpp"

Vehicle::Vehicle(std::string brand, std::string model, unsigned int year,
	std::string problem, LevelProblem level)
	:brand(brand), model(model), year(year), problem(problem), level(level){}

std::string Vehicle::getBrand() const
{
	return brand;
}

std::string Vehicle::getModel() const
{
	return model;
}

unsigned int Vehicle::getYear() const
{
	return year;
}

std::string Vehicle::getProblem() const
{
	return problem;
}

LevelProblem Vehicle::getLevel() const
{
	return level;
}

int Vehicle::levelToPoints() const
{
	if (level == LevelProblem::LOW) {
		return 1;
	}
	else if (level == LevelProblem::MEDIUM) {
		return 3;
	}
	else {
		return 5;
	}
}
