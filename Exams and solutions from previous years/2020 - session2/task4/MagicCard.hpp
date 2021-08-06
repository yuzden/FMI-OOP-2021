#pragma once
#include "Card.hpp"

class MagicCard : virtual public Card {
protected:
	std::string effect;
public:
	MagicCard(const std::string& name = "",const unsigned int& cardNumber = 0,
		const unsigned int& imageNumber = 0, const std::string& effect = "");

	std::string getEffect() const;
	
	void print() const override;
	Card* copy() const override;
};