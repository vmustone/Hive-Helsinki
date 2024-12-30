#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
    std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure& other ) : AMateria("cure") {
	std::cout << "Cure copy constructor" << std::endl;
    _type = other._type;
}

Cure&   Cure::operator=(const Cure& other) {
	std::cout << "Cure assignation operator called" << std::endl;
    if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AMateria* Cure::clone() const {
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}