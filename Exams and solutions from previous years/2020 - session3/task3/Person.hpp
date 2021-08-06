#pragma once
#include <iostream>
#include <fstream>

class Person {
	char* firstName;
	char* lastName;

	char* copyCharArray(const char* source);
public:
	Person();
	Person(const char* firstName, const char* lastName);
	Person& operator=(const Person&);
	~Person();

	void setFirstName(const char* newFirstName);
	void setLastName(const char* newLastName);

	char* getFirstName() const;
	char* getLastName() const;

	friend std::istream& operator >>(std::istream& in, Person&);
	friend std::ostream& operator <<(std::ostream& out, const Person&);

	void writeInFile(const char* fileName) const;
};