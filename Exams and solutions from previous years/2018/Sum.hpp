#pragma once
#include "Expression.hpp"

class Sum : public Expression  {
	double value1;
public:
	Sum(Expression*, Expression*);

	double value() const override;
	void print() const override;
};