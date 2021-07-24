#pragma once
#include "Counter.hpp"

class TwowayCounter : virtual public Counter {
public:
	TwowayCounter(int initial = 0, unsigned step = 1);
	void decrement();
};