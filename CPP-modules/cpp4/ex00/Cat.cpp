#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

void	Cat::makeSound() const{
	std::cout << "Meow meow!" << std::endl;
}
