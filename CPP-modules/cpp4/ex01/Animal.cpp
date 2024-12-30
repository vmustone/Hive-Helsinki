#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
	type = "Animal";
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called" << std::endl;
	type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string Animal::getType() const{
	return type;
}

void	Animal::makeSound() const{
	std::cout << "Sound of Animal" << std::endl;
}