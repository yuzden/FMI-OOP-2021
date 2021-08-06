#include "RestaurantItem.hpp"

RestaurantItem::RestaurantItem(ItemType type, unsigned int stock, double price)
	:type(type), stock(stock), price(price){}

void RestaurantItem::print() const
{
	std::cout << "Type: " << type << std::endl;
	std::cout << "Stock: " << stock << std::endl;
	std::cout << "Price: " << price << std::endl;
}

ItemType RestaurantItem::getType() const
{
	return type;
}

unsigned int RestaurantItem::getStock() const
{
	return stock;
}

double RestaurantItem::getPrice() const
{
	return price;
}

void RestaurantItem::setType(const ItemType& newType)
{
	type = newType;
}

void RestaurantItem::setStock(const unsigned int& newStock)
{
	stock = newStock;
}

void RestaurantItem::setPrice(const double& newPrice)
{
	price = newPrice;
}


