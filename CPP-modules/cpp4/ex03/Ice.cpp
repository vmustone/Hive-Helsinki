#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria("ice") {
    std::cout << "Ice copy constructor called" << std::endl;
	_type = other._type;
}

Ice&   Ice::operator=( const Ice& rhs ) {
	std::cout << "Ice assignation operator called" << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

AMateria* Ice::clone() const {
    return (new Ice(*this));
}

void    Ice::use( ICharacter& target ) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}