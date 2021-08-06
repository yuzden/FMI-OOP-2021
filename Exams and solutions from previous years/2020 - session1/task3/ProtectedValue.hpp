#pragma once
#include <stdexcept>

template <typename T>
class ProtectedValue {
	 T value;
	unsigned int code;
public:
	ProtectedValue(const T& value = T(), unsigned int code =0);

	T getValue(unsigned int validCode)const;
};

template<typename T>
ProtectedValue<T>::ProtectedValue(const T& value, unsigned int code)
	:value(value), code(code) {}

template<typename T>
T ProtectedValue<T>::getValue(unsigned int validCode) const
{
	if (validCode == code) {
		return value;
	}
	else {
		throw std::invalid_argument("");
	}
}
