#include "SpecialCard.hpp"


SpecialCard::SpecialCard(const std::string& name, const unsigned int& cardNumber, const unsigned int& imageNumber,
	const unsigned int& atackPower, const unsigned int& protectPower,
	const std::string& effect, const unsigned int& level)
	:Card(name, cardNumber, imageNumber), HeroCard(name, cardNumber, imageNumber, atackPower, protectPower),
	MagicCard(name, cardNumber, imageNumber, effect), level(level)
{
}

unsigned int SpecialCard::getLevel() const
{
	return level;
}

void SpecialCard::print() const
{
	HeroCard::print();
	std::cout << "Effect: " << effect << std::endl;
	std::cout << "Level: " << level << std::endl;
}

Card* SpecialCard::copy() const
{
	return new SpecialCard(*this);
}
