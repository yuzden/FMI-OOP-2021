#pragma once
#include "Card.hpp"

class HeroCard : virtual public Card {
protected:
	unsigned int atackPower;
	unsigned int protectPower;
public:
	HeroCard(const std::string& name = "",const unsigned int& cardNumber = 0, 
		const unsigned int& imageNumber = 0,const unsigned int& atackPower =0 , const unsigned int& protectPower = 0);

	unsigned int getAtackPower() const;
	unsigned int gerProtectPower() const;

	void print() const override;
	Card* copy() const override;
};