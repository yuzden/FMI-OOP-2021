#pragma once
#include "StoreItem.hpp"
#include <string>

class Vegetable: public StoreItem {
	std::string name, sort;
public:
	Vegetable(ItemType = ItemType::VEGETABLE, unsigned int cal = 0, double price = 0, std::string name = "", std::string sort = "");
	const std::string getName() const;
	void setName(std::string);
	void setSort(std::string);

	bool operator==(const Vegetable&);

	void print() const override;

	StoreItem* copy() const override;
};