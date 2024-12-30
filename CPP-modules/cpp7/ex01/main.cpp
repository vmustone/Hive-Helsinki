#include "iter.hpp"
/*
int main() {
    int intArray[5] = {1, 2, 3, 4, 5};
    std::size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Iterating over integers: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    double doubleArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Iterating over doubles: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;

    std::string stringArray[5] = {"apple", "banana", "orange", "grape", "kiwi"};
    std::size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Iterating over strings: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
*/

class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T & x ) { std::cout << x << std::endl; return; }
int main() {
int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
Awesome tab2[5];
iter( tab, 5, print<int> );
iter( tab2, 5, print<Awesome> );
return 0;
}