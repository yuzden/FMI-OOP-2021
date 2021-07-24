#pragma once
#include <iostream>

class Expression {
protected:
	double valueExpr;
public:
	Expression(double value = 0);
	~Expression() = default;

	virtual double value() const;
	virtual void print() const = 0;
};