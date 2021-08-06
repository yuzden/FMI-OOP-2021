#include "Shop.hpp"

void Shop::copyOther(const Shop& rhs) 
{
	for (auto item : rhs.items) {
		items.push_back(item->copy());
	}
}

void Shop::deleteAll()
{
	for (auto item : items) {
		delete item;
	}
	items.clear();
}

Shop::Shop(const Shop& rhs)
	:shopName(rhs.shopName)
{
	copyOther(rhs);
}

Shop& Shop::operator=(const Shop& rhs)
{
	if (&rhs != this) {
		deleteAll();
		copyOther(rhs);
		shopName = rhs.shopName;
	}
	return *this;
}

Shop::~Shop()
{
	deleteAll();
}

void Shop::add(const StoreItem* newItem)
{
	items.push_back(newItem->copy());
}

void Shop::removeItem(unsigned index)
{
	delete items[index];
	items.erase(items.begin() + index);
}

void Shop::changePrice(unsigned index, double newPrice)
{
	items[index]->setPrice(newPrice);
}

void Shop::changeName(unsigned index, std::string newName)
{
	items[index]->setName(newName);
}

void Shop::printAll() const
{
	for (auto item : items) {
		item->print();
	}
}




