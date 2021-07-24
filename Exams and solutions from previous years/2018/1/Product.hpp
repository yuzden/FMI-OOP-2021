#pragma once
#include "Expression.hpp"

class Product : public Expression {
	double value1;
public:
	Product(Expression*, Expression*);

	double value() const override;
	void print() const override;
};
