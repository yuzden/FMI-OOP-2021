#pragma once
#include <string>
#include <vector>
#include "Observer.hpp"
#include "ConcreteObserver.hpp"


class CentralBank {
	std::string bankName;
	std::vector<std::pair<std::string, double>> currencyRates;
	std::vector<Observer*> observers;

	void deleteAll();
	void copyOther(const CentralBank&);
public:
	CentralBank(const std::string& name = "");
	CentralBank(const CentralBank&);
	CentralBank& operator= (const CentralBank&);
	~CentralBank();

	void addCurrency(std::pair<std::string, double>);
	void deleteCurrency(unsigned int);
	void setRate(const std::string&, double);

	void registerr(ConcreteObserver*);
	void unregisterr(unsigned int);
	void notify(const std::string& currency, double rate);
};