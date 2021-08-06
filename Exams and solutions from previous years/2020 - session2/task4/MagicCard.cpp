#include "MagicCard.hpp"

MagicCard::MagicCard(const std::string& name,const unsigned int& cardNumber, 
	const unsigned int& imageNumber,const std::string& effect)
	:Card(name, cardNumber,imageNumber),effect(effect){}

std::string MagicCard::getEffect() const
{
	return effect;
}

void MagicCard::print() const
{
	Card::print();
	std::cout << "Effect: " << effect << std::endl;
}

Card* MagicCard::copy() const
{
	return new MagicCard(*this);
}
