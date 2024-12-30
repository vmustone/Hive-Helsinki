#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal constructor called" << std::endl;
	type = "AAnimal";
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string AAnimal::getType() const{
	return type;
}

void	AAnimal::makeSound() const{
	std::cout << "Sound of AAnimal" << std::endl;
}