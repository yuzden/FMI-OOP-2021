#include "ConcreteObserver.hpp"

ConcreteObserver::ConcreteObserver(const std::string& name)
	:observerName(name), Observer()
{
}

void ConcreteObserver::update(std::string currency, double rate) const
{
	std::cout << "Update " << observerName << ':' << currency << rate << std::endl;
}

Observer* ConcreteObserver::copy() const
{
	return new ConcreteObserver(*this);
}
