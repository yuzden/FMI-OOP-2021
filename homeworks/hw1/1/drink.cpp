#include "drink.hpp"

Drink::Drink()
	:calories(0), quantity(0), price(0)
{
	name = new char[1];
	strcpy(name, "");
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
	:calories(init_calories), quantity(init_quantity), price(init_price)
{
	copy_name(init_name);
}

Drink::Drink(const Drink& rhs)
	: calories(rhs.calories), quantity(rhs.quantity), price(rhs.price)
{
	copy_name(rhs.name);
}

Drink& Drink::operator=(const Drink& rhs)
{
	if (&rhs != this)
	{
		set_name(rhs.name);
		calories = rhs.calories;
		quantity = rhs.quantity;
		price = rhs.price;
	}
	return *this;
}

Drink::~Drink()
{
	delete[] name;
}

const char* Drink::get_name() const
{
	return name;
}

int Drink::get_calories() const
{
	return calories;
}

double Drink::get_quantity() const
{
	return quantity;
}

double Drink::get_price() const
{
	return price;
}

void Drink::set_name(const char* new_name)
{
	delete[]name;
	copy_name(new_name);
}

void Drink::copy_name(const char* source)
{
	int newSize = strlen(source) + 1;
	name = new char[newSize];
	strcpy(name, source);
}