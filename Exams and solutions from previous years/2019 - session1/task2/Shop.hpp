#pragma once
#include "Vegetable.hpp"
#include "Fruit.hpp"
#include <vector>

class Shop {
	std::vector<StoreItem*> items;

	void deleteAll();
	void copyOther(const Shop&);
public:
	Shop() = default;
	Shop(const Shop&);
	Shop& operator=(const Shop&);
	~Shop();

	void add(StoreItem*);
	void deleteItem(unsigned int index);
	void changePrice(unsigned int index, double newPrice);
	void changeName(unsigned int index, std::string newName);
	void printAllItems() const;
	void findMostCal() const;
};