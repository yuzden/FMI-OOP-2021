#pragma once
#include "Observer.hpp"
#include <iostream>

class ConcreteObserver : public Observer {
	std::string observerName;
public:
	ConcreteObserver(const std::string&);

	void update(std::string, double) const override;
	Observer* copy() const override;
};