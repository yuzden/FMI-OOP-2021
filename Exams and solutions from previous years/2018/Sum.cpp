#include "Sum.hpp"

Sum::Sum(Expression* valueExpr, Expression* value1)
    :Expression(valueExpr->value())
{
   this->value1 = value1->value();
}

double Sum::value() const
{
    return value1 + valueExpr;
}

void Sum::print() const
{
    std::cout << valueExpr << '+' << value1 << std::endl;
}




