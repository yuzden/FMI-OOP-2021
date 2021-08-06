#include "Food.hpp"

Food::Food(ItemType type, unsigned int stock, double price, std::string name, double amount)
	:RestaurantItem(ItemType::FOOD, stock, price), name(name), amount(amount){}

std::string Food::getName() const
{
	return name;
}

void Food::setName(const std::string& newName)
{
	name = newName;
}

void Food::setAmount(const double& newAmount)
{
	amount = newAmount;
}

bool Food::operator>(const Food& rhs)
{
	return amount > rhs.amount;
}

void Food::print() const
{
	RestaurantItem::print();
	std::cout << "Name: " << name << std::endl;
	std::cout << "Amount: " << amount << std::endl;
}

RestaurantItem* Food::copy() const
{
	return new Food(*this);
}

