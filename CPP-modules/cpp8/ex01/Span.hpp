#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {

	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
		Span();

	public:
		Span(unsigned int num);
		~Span();
		Span(const Span &other);
		Span& operator=(const Span &other);

		void addNumber(int number);
		void addNumbers(const unsigned int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();

};

#endif