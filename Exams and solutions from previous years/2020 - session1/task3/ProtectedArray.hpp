#pragma once
#include "ProtectedValue.hpp"

template <typename T>
class ProtectedArray {
	ProtectedValue<T>* arrayValue = nullptr;
	unsigned int size = 0;

	void copyArray(const ProtectedArray&);
public:
	ProtectedArray() = default;
	ProtectedArray(const ProtectedArray&);
	ProtectedArray<T>& operator=(const ProtectedArray&);
	~ProtectedArray();

	void addValue(const T& value, const unsigned int& code);

	T getValueFromID(const unsigned int& index, const unsigned int& code) const;

};

template<typename T>
void ProtectedArray<T>::copyArray(const ProtectedArray& other)
{
	arrayValue = new ProtectedValue[other.size];
	for (int i = 0; i < other.size; i++) {
		arrayValue[i] = other.arrayValue[i];
	}
}

template<typename T>
 ProtectedArray<T>::ProtectedArray(const ProtectedArray& rhs)
	 :size(rhs.size)
{
	 copyArray(rhs);
}

 template<typename T>
 ProtectedArray<T>& ProtectedArray<T>::operator=(const ProtectedArray& rhs)
 {
	 if (&rhs != this) {
		 delete[] arrayValue;
		 copyArray(rhs);
		 size = rhs.size;
	 }
	 return *this;
 }

 template<typename T>
 ProtectedArray<T>::~ProtectedArray()
 {
	 delete[] arrayValue;
	 arrayValue = nullptr;
	 size = 0;
 }

 template<typename T>
 void ProtectedArray<T>::addValue(const T& value, const  unsigned int& code)
 {
	 ProtectedValue<T>* newArrayValue = new ProtectedValue<T>[size + 1];
	 for (int i = 0; i < size; i++) {
		 newArrayValue[i] = arrayValue[i];
	 }
	 newArrayValue[size] = ProtectedValue<T>(value, code);
	 size++;

	 delete[] arrayValue;
	 arrayValue = newArrayValue;
 }

 template<typename T>
 T ProtectedArray<T>::getValueFromID(const unsigned int & index, const unsigned int& code) const
 {
	 if (index < size) {
		 return arrayValue[index].getValue(code);
	 }
	 else {
		 throw std::invalid_argument("");
	 }
 }
