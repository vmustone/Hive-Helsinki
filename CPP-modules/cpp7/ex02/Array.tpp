#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(nullptr), arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), arraySize(n) {}

template <typename T>
Array<T>::Array(Array<T> const &other) : elements(new T[other.arraySize]), arraySize(other.arraySize) {
	for (unsigned int i = 0; i < arraySize; i++) {
		elements[i] = other.elements[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other) {
	if (this != &other) {
		delete[] elements;

		arraySize = other.arraySize;
		elements = new T[arraySize];

		for (unsigned int i = 0; i < arraySize; i++) {
			elements[i] = other.elements[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
T& Array<T>::operator[](const unsigned int index) const {
	if (index >= arraySize) {
		throw std::exception();
	}
	return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return arraySize;
}