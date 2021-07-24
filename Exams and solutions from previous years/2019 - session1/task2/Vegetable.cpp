#include "Vegetable.hpp"

Vegetable::Vegetable(ItemType, unsigned int cal, double price, std::string name, std::string sort)
	:StoreItem(ItemType::VEGETABLE, cal, price), name(name), sort(sort) {}

const std::string Vegetable::getName() const
{
	return name;
}

void Vegetable::setName(std::string newName)
{
	name = newName;
}

void Vegetable::setSort(std::string newSort)
{
	sort = newSort;
}

bool Vegetable::operator==(const Vegetable& rhs)
{
	return sort == rhs.sort;
}

void Vegetable::print() const
{
	StoreItem::print();
	std::cout << "Name: " << name << std::endl;
	std::cout << "Sort: " << sort << std::endl;
}

StoreItem* Vegetable::copy() const
{
	return new Vegetable(*this);
}
