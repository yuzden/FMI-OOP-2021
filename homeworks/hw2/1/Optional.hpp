#pragma once
#include <iostream>

template <typename T>
class Optional {
    T value;

public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;
};

template<typename T>
Optional<T>::Optional()
    :value(T())
{
}

template<typename T>
Optional<T>::Optional(const T& value)
    :value(value)
{
}

template<typename T>
bool Optional<T>::is_none() const
{
    if (value == T()) {
        return true;
    }
    return false;
}

template<typename T>
T Optional<T>::get_value() const
{
    return value;
}


