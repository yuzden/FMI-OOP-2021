#pragma once
#include "Expression.hpp"
#include <cstring>
#pragma warning(disable : 4996)

class Var: public Expression {
	char* name;
	unsigned int charSize;
	void copyChar(const char*);

public:
	Var(char* name = nullptr, unsigned int size = 0, double value = 0);
	Var(const Var&);
	Var& operator=(const Var&);
	~Var();

	void print() const override;
	void setValue(double newValueExpr);
};