#pragma once

#include "Container.hpp"

template <typename T>
class Set : public Container<T> {
public:
	bool add(const T&) override;
};

template<typename T>
bool Set<T>::add(const T& newElement)
{
	if (member(newElement)) {
		return false;
	}

	return Container<T>::add(newElement);
}
