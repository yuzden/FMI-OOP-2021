#include "StoreItem.hpp"

StoreItem::StoreItem(TypeItem typeItem, std::string name, double pirce, std::string color)
	:typeItem(typeItem), name(name), price(price), color(color){}

TypeItem StoreItem::getType() const
{
	return typeItem;
}

std::string StoreItem::getName() const
{
	return name;
}

double StoreItem::getPrice() const
{
	return price;
}

std::string StoreItem::getColor() const
{
	return color;
}

void StoreItem::setType(const TypeItem& newType)
{
	typeItem = newType;
}

void StoreItem::setName(const std::string& newName)
{
	name = newName;
}

void StoreItem::setPrice(const double& newPrice)
{
	price = newPrice;
}

void StoreItem::setColor(const std::string& newColor)
{
	color = newColor;
}

void StoreItem::print() const
{
	std::cout << "Type: " << typeItem << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Color: " << color << std::endl;
}

