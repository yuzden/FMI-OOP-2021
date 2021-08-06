#pragma once
//#ifdef  ArrayVector_hpp
//#define ArrayVector_hpp
#include "Container.hpp"

template <typename T>
class ArrayVector : public Container<T>{
	unsigned int maxSize;
public:
	ArrayVector(unsigned int maxSize = 10);
	bool add(const T&) override;

	unsigned int getMaxSize() const;
};

template<typename T>
ArrayVector<T>::ArrayVector(unsigned int maxSize)
       :Container<T>(),maxSize(maxSize){}

template<typename T>
bool ArrayVector<T>::add(const T& newElement) {
	if (length == maxSize) {
		return false;
	}
	return Container<T>::add(newElement);
}

template<typename T>
unsigned int ArrayVector<T>::getMaxSize()const {
	return maxSize;
}

//#endif ArrayVector_hpp