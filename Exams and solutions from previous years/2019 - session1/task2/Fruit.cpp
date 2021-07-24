#include "Fruit.hpp"

Fruit::Fruit(ItemType type, unsigned int cal, double price, std::string name, std::string color)
	:StoreItem(ItemType::FRUIT, cal, price), name(name), color(color){}

const std::string Fruit::getName() const
{
	return name;
}

void Fruit::setName(std::string newName)
{
	name = newName;
}

void Fruit::setColor(std::string newColor)
{
	color = newColor;
}

bool Fruit::operator>(const Fruit& other)
{
	return cal > other.cal;
}

void Fruit::print() const
{
	StoreItem::print();
	std::cout << "Name: " << name << std::endl;
	std::cout << "Color: " << color << std::endl;
}

StoreItem* Fruit::copy() const
{
	return new Fruit(*this);
}
