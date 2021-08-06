#pragma once
#include "Vehicle.hpp"

class Bus : public Vehicle {
	bool isFull;
public:
	Bus(std::string brand = "", std::string model = "", unsigned int year = 0,
		std::string problem = "", LevelProblem level = LevelProblem::DEFAULT, bool isFull = false);

	bool getIsFull() const;

	Vehicle* copy()const override;
};