#pragma once
#include <string>
#include <iostream>

class Card {
protected:
	std::string name;
	unsigned int cardNumber;
	unsigned int imageNumber;
public:
	Card(const std::string& name = "",const unsigned int& cardNumber = 0, const unsigned int& imageNumber = 0);
	virtual ~Card() = default;

	std::string getName() const;
	unsigned int getCardNumber() const;
	unsigned int getImageNumber() const;

	virtual void print() const = 0;

	virtual Card* copy() const = 0;
};