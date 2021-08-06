#pragma once
#include <vector>
#include "Drink.hpp"
#include "Food.hpp"

class Restaurant {
	std::vector<RestaurantItem*> items;

	void copyOther(const Restaurant&);
	void deleteAll();
public:
	Restaurant() = default;
	Restaurant(const Restaurant&);
	Restaurant& operator=(const Restaurant&);
	~Restaurant();

	void add(RestaurantItem*);
	void deleteItem(unsigned int index);
	void changePrice(unsigned int index, double newPrice);
	void changeName(unsigned int index, std::string newName);

	void printAllItems() const;
	void printAlcoholFree() const;
};