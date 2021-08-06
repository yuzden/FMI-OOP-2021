#pragma once

#include <vector>
#include "Shoes.hpp"
#include "TShirt.hpp"


class Shop {
	std::vector<StoreItem*> items;
	std::string shopName;
	
	void copyOther(const Shop&);
	void deleteAll();
public:
	Shop() = default;
	Shop(const Shop&);
	Shop& operator=(const Shop&);
	~Shop();

	void add(const StoreItem*);
	void removeItem(unsigned index);
	void changePrice(unsigned index, double newPrice);
	void changeName(unsigned index, std::string newName);
	void printAll() const;
};