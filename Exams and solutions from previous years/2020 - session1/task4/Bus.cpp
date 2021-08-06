#include "Bus.hpp"

Bus::Bus(std::string brand, std::string model, unsigned int year,
	std::string problem, LevelProblem level, bool isFull)
	:Vehicle(brand, model, year, problem, level), isFull(isFull) {}

bool Bus::getIsFull() const
{
	return isFull;
}

Vehicle* Bus::copy() const
{
	return new Bus(*this);
}
