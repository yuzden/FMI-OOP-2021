#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max)
	:Counter(),LimitedCounter(max), Min(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial)
	:Counter(initial), LimitedCounter(max, initial), TwowayCounter(initial), Min(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step)
	:Counter(initial, step), LimitedCounter(max, initial, step), TwowayCounter(initial, step), Min(min)
{
}

void LimitedTwowayCounter::increment() 
{
	int temp = Total + Step;
	if (temp <= Max)
	{
		Counter::increment();
	}
}

void LimitedTwowayCounter::decrement()
{
	int temp = Total - Step;
	if (temp >= Min) {
		Total = temp;
	}
}

int LimitedTwowayCounter::getMin() const
{
	return Min;
}

