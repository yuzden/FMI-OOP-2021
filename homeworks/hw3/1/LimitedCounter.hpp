#pragma once
#include "Counter.hpp"
class LimitedCounter :  virtual public Counter {
public:
	LimitedCounter(int max);
	LimitedCounter(int max, int initial);
	LimitedCounter(int max, int initial, unsigned step);

	void increment();

	int getMax() const;
	int getTotal() const;
	const int getStep() const;
	
protected:
	int Max;
};
