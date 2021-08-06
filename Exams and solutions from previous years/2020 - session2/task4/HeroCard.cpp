#include "HeroCard.hpp"

HeroCard::HeroCard(const std::string& name, const unsigned int& cardNumber,
	const unsigned int& imageNumber, const unsigned int& atackPower, const unsigned int& protectPower)
	:Card(name, cardNumber, imageNumber), atackPower(atackPower), protectPower(protectPower)
{
}

unsigned int HeroCard::getAtackPower() const
{
	return atackPower;
}

unsigned int HeroCard::gerProtectPower() const
{
	return protectPower;
}

void HeroCard::print() const
{
	Card::print();
	std::cout << "Atack Power: " << atackPower << std::endl;
	std::cout << "ProtectPower: " << protectPower << std::endl;
}

Card* HeroCard::copy() const
{
	return new HeroCard(*this);
}
