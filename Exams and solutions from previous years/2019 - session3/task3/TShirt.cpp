#include "TShirt.hpp"

TShirt::TShirt(TypeItem typeItem, std::string name, double pirce, std::string color, std::string size)
	:StoreItem(TypeItem::TSHIRT, name, price, color), size(size) {}

std::string TShirt::getSize() const
{
	return size;
}

void TShirt::setSize(const std::string& newSize)
{
	size = newSize;
}

bool TShirt::operator==(const TShirt& rhs) const
{
	if (color == rhs.color && size == rhs.size) {
		return true;
	}
	return false;
}

void TShirt::print() const
{
	StoreItem::print();
	std::cout << "Size: " << size << std::endl;
}

StoreItem* TShirt::copy() const
{
	return new TShirt(*this);
}
