#include "Shoes.hpp"

Shoes::Shoes(TypeItem typeItem, std::string name, double pirce,
	std::string color, std::string typeOfShoes, double size)
	:StoreItem(TypeItem::SHOES, name, price, color), typeOfShoes(typeOfShoes), size(size) {}

std::string Shoes::getTypeOfShoes() const
{
	return typeOfShoes;
}

int Shoes::getSize() const
{
	return size;
}

void Shoes::setTypeOfShoes(const std::string& newType)
{
	typeOfShoes = newType;
}

void Shoes::setSize(const int& newSize)
{
	size = newSize;
}

bool Shoes::operator>(const Shoes& rhs) const
{
	return size > rhs.size;
}

void Shoes::print() const
{
	StoreItem::print();
	std::cout << "Type Of Shoes: " << typeOfShoes << std::endl;
	std::cout << "Size: " << this->size << std::endl;
}

StoreItem* Shoes::copy() const
{
	return new Shoes(*this);
}
