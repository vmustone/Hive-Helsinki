#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base::~Base() {}

Base* generate() {
	std::srand(std::time(NULL));
    int random = std::rand() % (3);
    if (random == 0)
		return (new A);
	else if (random == 1)
        return (new B);
    else
		return (new C);
}

void identify(Base* p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "* is A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "* is B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "* is C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a_ref = dynamic_cast<A&>(p);
        std::cout << "& is A" << std::endl;
    } catch(std::bad_cast& e) {
        try {
            B& b_ref = dynamic_cast<B&>(p);
            std::cout << "& is B" << std::endl;
        } catch(std::bad_cast& e) {
            C& c_ref = dynamic_cast<C&>(p);
            std::cout << "& is C" << std::endl;
        }
    }
}
