#include "StoreItem.hpp"

StoreItem::StoreItem(ItemType item, unsigned int cal, double price)
	:typeItem(item), cal(cal),price(price)
{
}

const ItemType StoreItem::GetTypeItem() const
{
	return typeItem;
}

const unsigned int StoreItem::GetCal() const
{
	return cal;
}

const double StoreItem::GetPrice() const
{
	return price;
}

void StoreItem::SetTypeItem(const ItemType item)
{
	typeItem = item;
}

void StoreItem::setCalorie(const unsigned int callories)
{
	cal = callories;
}

void StoreItem::setPrice(const double newPrice)
{
	price = newPrice;
}

void StoreItem::print() const
{
	std::cout << "Itemtype: " << typeItem << std::endl;
	std::cout << "Calories: " << cal << std::endl;
	std::cout << "Price: " << price << std::endl;
}
