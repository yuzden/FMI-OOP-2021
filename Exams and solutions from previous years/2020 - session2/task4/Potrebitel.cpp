#include "Potrebitel.hpp"

void Potrebitel::copyOther(const Potrebitel& rhs)
{
	for (auto card : rhs.cards) {
		cards.push_back(card->copy());
	}
}

void Potrebitel::deleteAll()
{
	for (auto card : cards) {
		delete card;
	}
	cards.clear();
}

Potrebitel::Potrebitel(const Potrebitel& rhs)
{
	copyOther(rhs);
}

Potrebitel& Potrebitel::operator=(const Potrebitel& rhs)
{
	if (&rhs != this) {
		deleteAll();
		copyOther(rhs);
	}
	return *this;
}

Potrebitel::~Potrebitel()
{
	deleteAll();
}

void Potrebitel::addCard(Card* newCard)
{
	cards.push_back(newCard->copy());
}

void Potrebitel::printAll() const
{
	for (auto card : cards) {
		card->print();
	}
}
