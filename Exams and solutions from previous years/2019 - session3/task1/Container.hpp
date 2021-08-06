#pragma once




template <typename T>
class Container {
protected:
	T* elements;
	unsigned int length;

	void copyContainer(const Container<T>&);
	int findIndex(const T&) const;
public:
	Container();
	Container(const Container<T>&);
	Container<T>& operator =(const Container<T>&);
	virtual ~Container();

	bool member(const T&) const;
	virtual bool add(const T&) = 0;
	bool remove(const T&);
	int size() const;
	T& operator [] (int i);

};

template<typename T>
void Container<T>::copyContainer(const Container<T>& other)
{
	if (!other.elements) {
		elements = nullptr;
		return;
	}
	elements = new T[other.length];
	length = other.length;
	for (int i = 0; i < length; i++) {
		elements[i] = other.elements[i];
	}
}

template<typename T>
int Container<T>::findIndex(const T& element) const
{
	for (int i = 0; i < length; i++) {
		if (elements[i] == element) {
			return i;
		}
	}
	return -1;
}

template<typename T>
Container<T>::Container()
	:elements(nullptr), length(0)
{
}

template<typename T>
Container<T>::Container(const Container<T>& other)
{
	copyContainer(other);
}

template<typename T>
Container<T>& Container<T>::operator=(const Container<T>& rhs)
{
	if (&rhs != this) {
		delete[] elements;
		copyContainer(rhs);
	}
	return *this;
}

template<typename T>
Container<T>::~Container()
{
	delete[] elements;
}

template<typename T>
bool Container<T>::member(const T& element) const
{
	return findIndex(element) != -1;
}

template<typename T>
bool Container<T>::add(const T& newElement)
{
	T* newElements = new T[length + 1];
	for (int i = 0; i < length; i++) {
		newElements[i] = elements[i];
	}
	newElements[length] = newElement;
	length++;
	delete[]elements;
	elements = newElements;
	return true;
}

template<typename T>
bool Container<T>::remove(const T& removeElement)
{
	if (!elements) {
		return false;
	}

	if (length == 1 && elements[0] == removeElement) {
		delete elements[0];
		elements = nullptr;
		length = 0;
		return true;
	}

	int index = findIndex(removeElement);

	if (index == -1) {
		return false;
	}

	T* newElements = new T[length - 1];
	length--;
	int idx = 0;
	for (int i = 0; i < length; i++) {
		if (idx != index) {
			newElements[i] = elements[idx];
			idx++;
		}
	}
	delete[] elements;
	elements = newElements;

	return true;
}

template<typename T>
int Container<T>::size() const
{
	return length;
}

template<typename T>
T& Container<T>::operator[](int i)
{
	return elements[i];
}

