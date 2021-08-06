#pragma once

#include "StoreItem.hpp"

class Shoes:public StoreItem {
	std::string typeOfShoes;
	int size;
public:
	Shoes(TypeItem typeItem = TypeItem::SHOES, std::string name = "",
		double pirce = 0, std::string color = "", 
		std::string typeOfShoes = "", double size = 0);
	std::string getTypeOfShoes() const;
	int getSize() const;

	void setTypeOfShoes(const std::string& newType);
	void setSize(const int& newSize);

	bool operator>(const Shoes&) const;

	void print() const override;
	StoreItem* copy()const override;
};