#include "Const.hpp"

Const::Const(double value)
	:Expression(value)
{
}

void Const::print() const
{
	std::cout << valueExpr << std::endl;
}
