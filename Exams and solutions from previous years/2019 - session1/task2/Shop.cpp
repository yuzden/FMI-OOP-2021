#include "Shop.hpp"

void Shop::deleteAll()
{
	for (auto item : items) {
		delete item;
	}
	items.clear();
}

void Shop::copyOther(const Shop& other)
{
	for (auto item : other.items) {
		items.push_back(item->copy());
	}
}

Shop::Shop(const Shop& rhs)
{
	copyOther(rhs);
}

Shop& Shop::operator=(const Shop& rhs)
{
	if (&rhs != this) {
		deleteAll();
		copyOther(rhs);
	}
	return *this;
}

Shop::~Shop()
{
	deleteAll();
}

void Shop::add(StoreItem* newItem)
{
	items.push_back(newItem->copy());
}

void Shop::deleteItem(unsigned int index)
{
	delete items[index];
	items.erase(items.begin() + index);
}

void Shop::changePrice(unsigned int index, double newPrice)
{
	items[index]->setPrice(newPrice);
}

void Shop::changeName(unsigned int index, std::string newName)
{
	if (items[index]->GetTypeItem() == ItemType::FRUIT) {
		auto* temp = dynamic_cast<Fruit*>(items[index]);
		if (temp) {
			temp->setName(newName);
		}
	}

	if (items[index]->GetTypeItem() == ItemType::VEGETABLE) {
		auto* temp = dynamic_cast<Vegetable*>(items[index]);
		if (temp) {
			temp->setName(newName);
		}
	}
}

void Shop::printAllItems() const
{
	for ( auto item : items) {
		item->print();
	}
}

void Shop::findMostCal() const
{
	int most = -1;
	for (int i = 0; i < items.size(); i++) {
		for(int j = i+1;j < items.size(); j++) {
			if (items[i]->GetCal() < items[j]->GetCal()) {
				most = j;
			}
		}
	}
	auto* temp = dynamic_cast<Fruit*> (items[most]);
	temp->print();
}




