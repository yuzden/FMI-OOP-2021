#include "CentralBank.hpp"

void CentralBank::deleteAll()
{
	for (auto observer : observers) {
		delete observer;
	}
	observers.clear();
	currencyRates.clear();
}

void CentralBank::copyOther(const CentralBank& rhs)
{
	bankName = rhs.bankName;
	
	for (auto pair : currencyRates) {
		currencyRates.push_back(pair);
	}

	for (auto observer : rhs.observers) {
		observers.push_back(observer->copy());
	}
}

CentralBank::CentralBank(const std::string& name)
	:bankName(name)
{
}

CentralBank::CentralBank(const CentralBank& other)
{
	copyOther(other);
}

CentralBank& CentralBank::operator=(const CentralBank& other)
{
	if (&other != this) {
		deleteAll();

		copyOther(other);
	}
	return *this;
}

CentralBank::~CentralBank()
{
	deleteAll();
}

void CentralBank::addCurrency(std::pair<std::string, double> newCurrencyRate)
{
	currencyRates.push_back(newCurrencyRate);
}

void CentralBank::deleteCurrency(unsigned int id)
{
	currencyRates.erase(currencyRates.begin() + id);
}

void CentralBank::setRate(const std::string& currency, double newRate)
{
	for (auto currencyRate : currencyRates) {
		if (currencyRate.first == currency) {
			currencyRate.second = newRate;
			notify(currency, newRate);
		}
	}
	
}

void CentralBank::registerr(ConcreteObserver* newObserver)
{
	observers.push_back(newObserver);
}

void CentralBank::unregisterr(unsigned int id)
{
	if (id < observers.size()) {
		delete observers[id];
		observers.erase(observers.begin() + id);
	}
}

void CentralBank::notify(const std::string& currency, double rate)
{
	for (auto observer : observers) {
		observer->update(currency, rate);
	}
}
