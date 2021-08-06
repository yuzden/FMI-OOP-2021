#pragma once

#include "Vehicle.hpp"

class Car:public Vehicle {
	bool isPersonal;
public:
	Car(std::string brand = "", std::string model = "", unsigned int year = 0,
		std::string problem = "", LevelProblem level = LevelProblem::DEFAULT, bool isPersonal = false);

	bool getIsPersonal() const;
	Vehicle* copy() const override;

};