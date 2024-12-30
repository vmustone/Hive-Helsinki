#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array {
private:
    T* elements;
    unsigned int arraySize;

public:
    Array();
    Array(unsigned int n);
    Array(Array<T> const &other);
    Array<T> &operator=(Array<T> const &other);
    ~Array();
    T& operator[](const unsigned int index) const;
    unsigned int size() const;
};

#include "Array.tpp"

#endif