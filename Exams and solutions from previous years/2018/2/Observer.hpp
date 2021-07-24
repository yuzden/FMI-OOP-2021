#pragma once
#include <string>
class Observer {
public:
	Observer() = default;
	virtual ~Observer() = default;

	virtual Observer* copy() const = 0;
	virtual void update(std::string, double) const = 0;
};