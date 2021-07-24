#include "VendingMachine.hpp"

VendingMachine::VendingMachine()
	:income(0), size(0), drinks(nullptr)
{
}

VendingMachine::VendingMachine(const VendingMachine& from)
	: income(from.income)
{
	copyDrinks(from.drinks, from.size);
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (&from != this)
	{
		income = from.income;
     	delete[] drinks;
		copyDrinks(from.drinks, from.size);
	}
	return *this;
}

VendingMachine::~VendingMachine()
{
	delete[] drinks;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	for (int i = 0; i < size; i++) {
		if (strcmp(to_add.get_name(), drinks[i].get_name()) == 0) {
			return false;
		}
	}

	unsigned int newSize = size + 1;
	Drink* newDrinks = new Drink[newSize];
	for (int i = 0; i < size; i++)
	{
		newDrinks[i] = drinks[i];
	}
	newDrinks[newSize - 1] = to_add;

	delete[] drinks;
	drinks = newDrinks;
	size = newSize;

	return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	int index = getIndex(drink_name);

	if (index == -1) {
		return 2;
	}

	if (money >= drinks[index].get_price()) {
		removeDrink(index);
		income += money;
		return 0;
	}

	income += money;
	return 1;
}

double VendingMachine::get_income() const
{
	return income;
}

void VendingMachine::removeDrink(unsigned int index)
{
	if (size == 1)
	{
		delete[] drinks;
		drinks = nullptr;
		size = 0;
		return;
	}

	unsigned int newSize = size - 1;
	Drink* newDrinks = new Drink[newSize];

	for (int i = 0; i < index; i++)
	{
		newDrinks[i] = drinks[i];
	}

	for (int i = index; i < newSize; i++)
	{
		newDrinks[i] = drinks[i + 1];
	}

	delete[] drinks;

	drinks = newDrinks;
	size = newSize;
}

void VendingMachine::copyDrinks(const Drink* source, unsigned int newSize) {
	if (size == 0)
	{
		drinks = nullptr;
		return;
	}

	drinks = new Drink[newSize];
	for (int i = 0; i < newSize; i++)
	{
		drinks[i] = source[i];
	}
	size = newSize;
}

int VendingMachine::getIndex(const char* drink_name) const
{
	for (int i = 0; i < size; i++) {
		if (strcmp(drinks[i].get_name(), drink_name) == 0) {
			return i;
		}
	}
	return -1;
}

