#include "Restaurant.hpp"

void Restaurant::copyOther(const Restaurant& rhs)
{
	for (auto item : rhs.items) {
		items.push_back(item->copy());
	}
}

void Restaurant::deleteAll()
{
	for (auto item : items) {
		delete item;
	}
	items.clear();
}

Restaurant::Restaurant(const Restaurant& rhs)
{
	copyOther(rhs);
}

Restaurant& Restaurant::operator=(const Restaurant& rhs)
{
	if (&rhs != this) {
		deleteAll();
		copyOther(rhs);
	}
	return *this;
}

Restaurant::~Restaurant()
{
	deleteAll();
}

void Restaurant::add(RestaurantItem* newItem)
{
	items.push_back(newItem->copy());
}

void Restaurant::deleteItem(unsigned int index)
{
	delete items[index];
	items.erase(items.begin() + index);
}

void Restaurant::changePrice(unsigned int index, double newPrice)
{
	items[index]->setPrice(newPrice);
}

void Restaurant::changeName(unsigned int index, std::string newName)
{
	if (items[index]->getType() == ItemType::DRINK) {
		auto* temp = dynamic_cast<Food*>(items[index]);
		temp->setName(newName);
	}
	else {
		auto* temp = dynamic_cast<Drink*>(items[index]);
		temp->setName(newName);
	}
}

void Restaurant::printAllItems() const
{
	for (auto item : items) {
		item->print();
	}
}

void Restaurant::printAlcoholFree() const
{
	for (auto item : items) {
		if (item->getType() == ItemType::DRINK) {
			auto* drink = dynamic_cast<Drink*>(item);
			if (drink->getAlcohol() == 0) {
				drink->print();
			}
		}
	}
}
