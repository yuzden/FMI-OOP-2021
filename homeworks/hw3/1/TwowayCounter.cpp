#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter(int initial, unsigned step)
	:Counter(initial,step){
}

void TwowayCounter::decrement()
{
	Total -= Step;
}
