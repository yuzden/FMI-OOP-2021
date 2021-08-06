#include "Card.hpp"

Card::Card(const std::string& name,const unsigned int& cardNumber,const unsigned int& imageNumber)
	:name(name), cardNumber(cardNumber), imageNumber(imageNumber) {}

std::string Card::getName() const
{
	return name;
}

unsigned int Card::getCardNumber() const
{
	return cardNumber;
}

unsigned int Card::getImageNumber() const
{
	return imageNumber;
}

void Card::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Number of Card: " << cardNumber << std::endl;
	std::cout << "Number of Image: " << imageNumber << std::endl;
}
