#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Wronganimal constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wronganimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = other.type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const{
	return type;
}

void	WrongAnimal::makeSound() const{
	std::cout << "Sound of WrongAnimal" << std::endl;
}