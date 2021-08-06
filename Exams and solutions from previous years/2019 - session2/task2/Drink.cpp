#include "Drink.hpp"

Drink::Drink(ItemType type, unsigned int stock, double price, std::string name, double alcohol)
	:RestaurantItem(ItemType::DRINK, stock, price), name(name), alcohol(alcohol)
{
}

std::string Drink::getName() const
{
	return name;
}

double Drink::getAlcohol() const
{
	return alcohol;
}

void Drink::setName(const std::string& newName)
{
	name = newName;
}

void Drink::setAlcohol(const double& newAlcohol)
{
	alcohol = newAlcohol;
}

bool Drink::operator>(const Drink& rhs)
{
	return alcohol > rhs.alcohol;
}

void Drink::print() const
{
	RestaurantItem::print();
	std::cout << "Name: " << name << std::endl;
	std::cout << "Alcohol: " << alcohol << std::endl;

}

RestaurantItem* Drink::copy() const
{
	return new Drink(*this);
}
