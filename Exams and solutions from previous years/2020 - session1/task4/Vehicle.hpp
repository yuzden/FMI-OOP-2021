#pragma once
#include <string>

enum LevelProblem {
	LOW,
	MEDIUM,
	HIHG,
	DEFAULT
};

class Vehicle {
protected:
	std::string brand;
	std::string model;
	unsigned int year;
	std::string problem;
	LevelProblem level;
public:
	Vehicle(std::string brand = "", std::string model = "", unsigned int year = 0,
		std::string problem ="", LevelProblem level = LevelProblem::DEFAULT);

	std::string getBrand() const;
	std::string getModel() const;
	unsigned int getYear() const;
	std::string getProblem() const;
	LevelProblem getLevel() const;

	virtual Vehicle* copy() const = 0;
	int levelToPoints() const;
};