#include "Product.hpp"

Product::Product(Expression* valueExpr, Expression* value1)
	:Expression(valueExpr->value())
{
	this->value1 = value1->value();
}

double Product::value() const
{
	return valueExpr * value1;
}

void Product::print() const
{
	std::cout << valueExpr << '*' << value1 << std::endl;
}
