#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
