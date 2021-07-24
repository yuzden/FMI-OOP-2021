#include "Var.hpp"

void Var::copyChar(const char* source)
{
    charSize = strlen(source) + 1;
    name = new char[charSize];
    strcpy(name, source);
}

Var::Var(char* name, unsigned int size, double value)
    :Expression(value), charSize(size)
{
    copyChar(name);
}

Var::Var(const Var& rhs)
{
    valueExpr = rhs.valueExpr;
    charSize = rhs.charSize;
    copyChar(rhs.name);
}

Var& Var::operator=(const Var& rhs) 
{
    if (&rhs != this) {
        delete[] name;
        valueExpr = rhs.valueExpr;
        charSize = rhs.charSize;
        copyChar(rhs.name);
    }
    return *this;
}

Var::~Var()
{
    delete[] name;
}

void Var::print() const
{
    std::cout << name << std::endl;
}

void Var::setValue(double newValueExpr)
{
    valueExpr = newValueExpr;
}


