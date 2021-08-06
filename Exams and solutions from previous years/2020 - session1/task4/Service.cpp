#include "Service.hpp"

void Service::copyOther(const Service& rhs)
{
	for (auto vehicle : rhs.vehicles) {
		vehicles.push_back(vehicle->copy());
	}
}

void Service::deleteAll()
{
	for (auto vehicle : vehicles) {
		delete vehicle;
	}
	vehicles.clear();
}

Service::Service(const Service& rhs)
{
	copyOther(rhs);
}

Service& Service::operator=(const Service& rhs)
{
	if (&rhs != this) {
		deleteAll();
		copyOther(rhs);
	}
	return *this;
}

Service::~Service()
{
	deleteAll();
}

void Service::addVehicle(Vehicle* newVehicle)
{
	if (newVehicle->levelToPoints() + hasSpace() < MAX) {
		vehicles.push_back(newVehicle->copy());
	}
}

int Service::hasSpace() const
{
	int sum = 0;
	for (auto vehicle : vehicles) {
		sum += vehicle->levelToPoints();
	}

	return sum;
}

void Service::print() const
{
	for (auto vehicle : vehicles) {
		std::cout << vehicle->getBrand() << " " << vehicle->getYear() << std::endl;
	}
}

