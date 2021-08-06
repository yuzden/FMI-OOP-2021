#pragma once
#include "RestaurantItem.hpp"
#include <string>

class Drink : public RestaurantItem {
	std::string name;
	double alcohol;
public:
	Drink(ItemType type = ItemType::DRINK, unsigned int stock = 0,
		double price = 0, std::string name = "", double alcohol = 0);

	std::string getName() const;
	double getAlcohol() const;
	
	void setName(const std::string&);
	void setAlcohol(const double&);

	bool operator>(const Drink&);

	void print() const override;

	RestaurantItem* copy() const override;
};
