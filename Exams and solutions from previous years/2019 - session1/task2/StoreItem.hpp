#pragma once
#include <iostream>

enum ItemType{
	FRUIT,
    VEGETABLE
};

class StoreItem {
protected:
	ItemType typeItem;
	unsigned int cal;
	double price;
public:
	StoreItem(ItemType, unsigned int cal = 0, double price = 0);
	~StoreItem() = default;

	virtual const ItemType GetTypeItem() const;
	virtual const unsigned int GetCal() const;
	virtual const double GetPrice() const;

	virtual void SetTypeItem(const ItemType);
	virtual void setCalorie(const unsigned int);
	virtual void setPrice(const double);

	virtual void print() const;

	virtual StoreItem* copy() const = 0;
};