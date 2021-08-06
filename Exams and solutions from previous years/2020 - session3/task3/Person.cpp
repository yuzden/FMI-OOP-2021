#include "Person.hpp"

char* Person::copyCharArray(const char* source)
{
	char* result = new char[strlen(source) + 1];
	strcpy(result, source);

	return result;
}

Person::Person()
{
	firstName = copyCharArray("");
	lastName = copyCharArray("");
}

Person::Person(const char* firstName, const char* lastName)
{
	this->firstName = copyCharArray(firstName);
	this->lastName = copyCharArray(lastName);
}

Person& Person::operator=(const Person& rhs)
{
	if (&rhs != this) {
		delete[] firstName;
		delete[] lastName;
		this->firstName = copyCharArray(rhs.firstName);
		this->lastName = copyCharArray(rhs.lastName);
	}
	return *this;
}

Person::~Person()
{
	delete[]firstName;
	delete[]lastName;
}

void Person::setFirstName(const char* newFirstName)
{
	delete[] firstName;
	firstName = copyCharArray(newFirstName);
}

void Person::setLastName(const char* newLastName)
{
	delete[] lastName;
	lastName = copyCharArray(newLastName);
}

char* Person::getFirstName() const
{
	return firstName;
}

char* Person::getLastName() const
{
	return lastName;
}

void Person::writeInFile(const char* fileName) const
{
	std::ofstream result(fileName, std::ios::app);

	if (result.is_open()) {
		result << this;
		result.close();
	}
}

std::istream& operator>>(std::istream& in, Person& object)
{
	char buff[100];
	
	in >> buff;
	object.setFirstName(buff);

	in >> buff;
	object.setLastName(buff);
}

std::ostream& operator<<(std::ostream& out, const Person& object)
{
	out << object.getFirstName() << " " << object.getLastName() << std::endl;
	return out;
}
