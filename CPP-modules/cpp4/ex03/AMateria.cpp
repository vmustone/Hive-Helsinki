
#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria constructor called" << std::endl;
	_type = "";
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
	std::cout << "AMateria type constructor called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << "AMateria copy constructor called" << std::endl;
	_type = other._type;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	std::cout << "AMateria assignation constructor called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

std::string const & AMateria::getType() const {
    return _type;
}

void    AMateria::use(ICharacter& target) {
    std::cout << "AMateria " << _type << " used on " << target.getName() << std::endl;
}