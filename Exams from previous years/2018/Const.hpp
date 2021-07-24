#pragma once
#include "Expression.hpp"

class Const : public Expression {
public:
	Const(double value);
	void print() const override;
};