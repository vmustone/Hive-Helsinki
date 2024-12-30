#include "Span.hpp"

Span::Span(unsigned int num) {
	_maxSize = num;
}

Span::~Span() {
}

Span::Span(const Span &other) {
	*this = other;
}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Cannot add more numbers. Maximum size reached.");
	}
    _numbers.push_back(number);
}

void Span::addNumbers(const unsigned int num) {
    for(unsigned int i = 0; i < num; i++) {
        addNumber(i);
		std::cout << "adding " << i << std::endl;
    }
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Cannot find span. Not enough numbers.");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];

    for (unsigned int i = 2; i < sortedNumbers.size(); ++i) {
        int currentSpan = sortedNumbers[i] - sortedNumbers[i - 1];
        minSpan = std::min(minSpan, currentSpan);
    }

    return minSpan;
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Cannot find span. Not enough numbers.");
    }
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    return std::abs(sortedNumbers.back() - sortedNumbers.front());
}