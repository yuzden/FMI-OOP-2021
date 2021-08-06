#pragma once
#include <iostream>

enum ItemType {
	FOOD,
	DRINK,
	DEFAULT
};

class RestaurantItem {
protected:
	ItemType type;
	unsigned int stock;
	double price;
public:
	RestaurantItem(ItemType type = ItemType::DEFAULT, unsigned int stock = 0, double price = 0);
	~RestaurantItem() = default;

	virtual void print() const;

	virtual ItemType getType() const;
	virtual unsigned int getStock() const;
	virtual double getPrice() const;

	virtual void setType(const ItemType&);
	virtual void setStock(const unsigned int&);
	virtual void setPrice(const double&);

	virtual RestaurantItem* copy() const = 0;
};