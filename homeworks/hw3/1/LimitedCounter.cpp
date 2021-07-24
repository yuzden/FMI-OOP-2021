#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max)
	:Counter(), Max(max)
{
}

LimitedCounter::LimitedCounter(int max, int initial)
	:Counter(initial, 1), Max(max)
{
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step)
	:Counter(initial,step), Max(max)
{
}

void LimitedCounter::increment()
{
	int temp = Total + Step;
	if (temp <= Max)
	{
		Counter::increment();
	}
	else {
	}
}

int LimitedCounter::getMax() const
{
	return Max;
}

int LimitedCounter::getTotal() const
{
	return Total;
}

const int LimitedCounter::getStep() const
{
	return Step;
}
