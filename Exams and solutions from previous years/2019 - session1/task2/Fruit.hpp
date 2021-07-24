#pragma once
#include "StoreItem.hpp"
#include <string>

class Fruit : public StoreItem {
	std::string name, color;
public:
	Fruit(ItemType = ItemType::FRUIT, unsigned int cal = 0, double price=0, std::string name= "", std::string color ="");

	const std::string getName() const;
	void setName(std::string);
	void setColor(std::string);

	bool operator>(const Fruit&);

	void print () const override; 

	StoreItem* copy() const override;
};
