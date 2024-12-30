#include "Base.hpp"

int main()
{
	Base *test = generate();
	Base &test_ref = *test;
	identify(test);
	identify(test_ref);
	delete (test);
	return(0);
}
