#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = other.type;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

void	WrongCat::makeSound() const{
	std::cout << "Meow meow!" << std::endl;
}