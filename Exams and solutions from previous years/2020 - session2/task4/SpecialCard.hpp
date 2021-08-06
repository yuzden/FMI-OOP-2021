#pragma once

#include "MagicCard.hpp"
#include "HeroCard.hpp"

class SpecialCard : public MagicCard, public HeroCard{
	unsigned int level;
public:
	SpecialCard(const std::string& name = "", const unsigned int& cardNumber = 0, const unsigned int& imageNumber = 0, 
		const unsigned int& atackPower = 0, const unsigned int& protectPower = 0,
		const std::string& effect = "", const unsigned int& level = 0);

	unsigned int getLevel() const;

	void print() const override;
	Card* copy() const override;
};