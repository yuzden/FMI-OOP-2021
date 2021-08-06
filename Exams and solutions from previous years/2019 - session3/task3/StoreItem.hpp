#pragma once
#include <string>
#include <iostream>

enum TypeItem {
	TSHIRT,
	SHOES,
	DEFAULT
};

class StoreItem {
protected:
	TypeItem typeItem;
	std::string name;
	double price;
	std::string color;
public:
	StoreItem(TypeItem typeItem = TypeItem::DEFAULT, std::string name = "", 
		double pirce = 0, std::string color = "");

	virtual TypeItem getType() const;
	virtual std::string getName() const;
	virtual double getPrice() const;
	virtual std::string getColor() const;

	virtual void setType(const TypeItem&);
	virtual void setName(const std::string&);
	virtual void setPrice(const double&);
	virtual void setColor(const std::string&);

	virtual void print() const;

	virtual StoreItem* copy()const = 0;
};