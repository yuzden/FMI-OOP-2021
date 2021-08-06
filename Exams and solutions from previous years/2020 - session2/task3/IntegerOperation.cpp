#include "IntegerOperation.hpp"

void IntegerOperation::copyOtherArray(const int* other, unsigned otherSize)
{
	if (!other) {
		elements = nullptr;
		return;
	}
	elements = new int[otherSize];
	for (int i = 0; i < otherSize; i++) {
		elements[i] = other[i];
	}
}

IntegerOperation::IntegerOperation()
	:elements(nullptr), size(0), result(0){}

IntegerOperation::IntegerOperation(const IntegerOperation& rhs)
	:size(rhs.size),result(rhs.result)
{
	copyOtherArray(rhs.elements, rhs.size);
}

IntegerOperation& IntegerOperation::operator=(const IntegerOperation& rhs)
{
	if (&rhs != this) {
		delete[] elements;
		size = rhs.size;
		result = rhs.result;
		copyOtherArray(rhs.elements, rhs.size);
	}
	return *this;
}

IntegerOperation::~IntegerOperation()
{
	delete[] elements;
}

void IntegerOperation::insert(int element)
{
	int* newElements = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}
	newElements[size] = element;
	delete[] elements;
	size++;
	elements = newElements;
}

int IntegerOperation::get_result() const
{
	return result;
}

void IntegerOperation::sum()
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += elements[i];
	}
	result = sum;
}

void IntegerOperation::sub()
{
	int sub = 0;
	for (int i = 0; i < size; i++) {
		sub -= elements[i];
	}
	result = sub;
}

void IntegerOperation::multiply()
{
	int multiply = 1;
	for (int i = 0; i < size; i++) {
		multiply *= elements[i];
	}
	result = multiply;
}

int IntegerOperation::operator+(IntegerOperation& rhs)
{
	sum();
	int sum1 = get_result();

	rhs.sum();
	int sum2 = rhs.get_result();

	return sum1 + sum2;
}

int IntegerOperation::operator-(IntegerOperation& rhs)
{
	sub();
	int sub1 = get_result();
	
	rhs.sub();
	int sub2 = rhs.get_result();

	return sub1 - sub2;
}

int IntegerOperation::operator*(IntegerOperation& rhs)
{
	multiply();
	int multi1 = get_result();

	rhs.multiply();
	int multi2 = rhs.get_result();

	return multi1 * multi2;
}
