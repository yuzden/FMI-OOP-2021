#include "Expression.hpp"

Expression::Expression(double value)
	: valueExpr(value)
{
}

double Expression::value() const
{
	return valueExpr;
}
