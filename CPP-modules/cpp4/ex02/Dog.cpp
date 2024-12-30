#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	try {
		_brain = new Brain();
	}
	catch (std::bad_alloc& e) {
		std::cout << "Issue while allocating" << std::endl;
	}
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		try {
			this->_brain = new Brain(*other._brain);
		}
		catch (std::bad_alloc& e) {
			std::cout << "Issue while allocating" << std::endl;
		}
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
