#include "Car.hpp"

Car::Car(std::string brand, std::string model, unsigned int year, std::string problem,
	LevelProblem level, bool isPersonal)
	:Vehicle(brand,model,year,problem, level), isPersonal(isPersonal){}

bool Car::getIsPersonal() const
{
	return isPersonal;
}

Vehicle* Car::copy() const
{
	return new Car(*this);
}
