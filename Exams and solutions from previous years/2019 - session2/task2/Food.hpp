#pragma once
#include "RestaurantItem.hpp"
#include <string>

class Food : public RestaurantItem {
	std::string name;
	double amount;
public:
	Food(ItemType type = ItemType::FOOD, unsigned int stock = 0, 
		double price = 0, std::string name = "", double amount = 0);

	std::string getName() const;

	void setName(const std::string&);
	void setAmount(const double&);

	bool operator>(const Food&);

	void print() const override;

	RestaurantItem* copy() const override;
};