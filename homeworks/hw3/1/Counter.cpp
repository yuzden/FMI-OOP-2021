#include "Counter.hpp"
Counter::Counter()
	:Total(0), Step(1) {
}

Counter::Counter(int initial)
	: Total(initial), Step(1) {
}

Counter::Counter(int initial, unsigned step)
	: Total(initial), Step(step) {
}

void Counter::increment()
{
	Total += Step;
}

int Counter::getTotal() const 
{
	return Total;
}

const int Counter::getStep() const
{
	return Step;
}
