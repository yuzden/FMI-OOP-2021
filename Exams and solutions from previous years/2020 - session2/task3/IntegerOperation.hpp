#pragma once

#ifndef IntegerOperation_hpp
#define IntegerOperation_hpp

class IntegerOperation {
	int* elements;
	unsigned size;
	int result;

	void copyOtherArray(const int* other, unsigned otherSize);
public:
	IntegerOperation();
	IntegerOperation(const IntegerOperation&);
	IntegerOperation& operator=(const IntegerOperation&);
	~IntegerOperation();

	void insert(int element);
	int get_result() const;

	void sum();
	void sub();
	void multiply();

	int operator+(IntegerOperation&);
	int operator-(IntegerOperation&);
	int operator*(IntegerOperation&);
};

#endif