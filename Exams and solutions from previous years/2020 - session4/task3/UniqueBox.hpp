#pragma once

template <typename T>
class UniqueBox {
	T* elements;
	int size; 

	void copyOther(const UniqueBox<T>&);
	bool findElement(const T&);

public:
	UniqueBox();
	UniqueBox(const UniqueBox<T>&);
	UniqueBox<T>& operator= (const UniqueBox<T>&);
	~UniqueBox();

	UniqueBox<T>& operator+=(const T& element);
	T& operator[](const unsigned& index);

	int get_counter() const;
};

template<typename T>
inline void UniqueBox<T>::copyOther(const UniqueBox<T>& other)
{
	if (!other.elements) {
		this->elements = nullptr;
		return;
	}
	this->elements = new T[other.size];
	for (int i = 0; i < other.size; i++) {
		this->elements[i] = other.elements[i];
	}
	this->size++;
}

template<typename T>
inline bool UniqueBox<T>::findElement(const T& toFind)
{
	for (int i = 0; i < size; i++) {
		if (elements[i] == toFind) {
			return true;
		}
	}
	return false;
}

template<typename T>
UniqueBox<T>::UniqueBox()
	:elements(nullptr), size(0)
{
}

template<typename T>
inline UniqueBox<T>::UniqueBox(const UniqueBox<T>& rhs)
	:size(rhs.size)
{
	copyOther(rhs);
}

template<typename T>
inline UniqueBox<T>& UniqueBox<T>::operator=(const UniqueBox<T>& rhs)
{
	if (&rhs != this) {
		delete[] elements;
		copyOther(rhs);
		this->size = rhs.size;
	}
	return *this;
}

template<typename T>
inline UniqueBox<T>::~UniqueBox()
{
	delete[] elements;
}

template<typename T>
inline UniqueBox<T>& UniqueBox<T>::operator+=(const T& element)
{
	if (!findElement(element)) {
		T* newElements = new T[size + 1];
		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i];
		}
		newElements[size] = element;
		delete[]elements;
		elements = newElements;
		size++;
	}
	return *this;
}

template<typename T>
inline T& UniqueBox<T>::operator[](const unsigned& index)
{
	return elements[index];
}

template<typename T>
inline int UniqueBox<T>::get_counter() const
{
	return size;
}
