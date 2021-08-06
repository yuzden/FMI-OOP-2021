#pragma once
#include "StoreItem.hpp"

class TShirt: public StoreItem {
	std::string size;
public:
	TShirt(TypeItem typeItem = TypeItem::TSHIRT, std::string name = "",
		double pirce = 0, std::string color = "", std::string size = "");
	std::string getSize() const;
	void setSize(const std::string&);

	bool operator==(const TShirt&) const;

	void print() const override;

	StoreItem* copy() const override;
};