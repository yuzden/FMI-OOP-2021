#pragma once
#include "MagicCard.hpp"
#include "HeroCard.hpp"
#include "SpecialCard.hpp"

#include <vector>

class Potrebitel {
	std::vector<Card*> cards;

	void copyOther(const Potrebitel&);
	void deleteAll();
public:
	Potrebitel() = default;
	Potrebitel(const Potrebitel&);
	Potrebitel& operator=(const Potrebitel&);
	~Potrebitel();

	void addCard(Card*);
	void printAll() const;

};