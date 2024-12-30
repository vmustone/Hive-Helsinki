#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	Span myspan = Span(0);
	try
	{
		myspan.addNumbers(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "no size" << std::endl;;
	}
	try
	{
		std::cout << "Largest DIFF " << myspan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "No values" << std::endl;;
	}
	
	Span myspan1 = Span(1000);
	myspan1.addNumbers(1000);
	try
	{
		myspan1.addNumbers(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: over limits." << std::endl;
	}
	
    return 0;
}
