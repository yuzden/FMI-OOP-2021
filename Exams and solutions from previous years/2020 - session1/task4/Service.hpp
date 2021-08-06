#pragma once
#include "Car.hpp"
#include "Bus.hpp"
#include <vector>
#include <iostream>

class Service {
	std::vector<Vehicle*> vehicles;
	const int MAX = 10;

	void copyOther(const Service&);
	void deleteAll();
public:
	Service() = default;
	Service(const Service&);
	Service& operator=(const Service&);
	~Service();

	void addVehicle(Vehicle*);
	int hasSpace() const;

	void print() const;

};