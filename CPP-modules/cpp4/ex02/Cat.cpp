#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	try {
		_brain = new Brain();
	}
	catch (std::bad_alloc& e) {
		std::cout << "Issue while allocating" << std::endl;
	}
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignation operator called" << std::endl;
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

void	Cat::makeSound() const{
	std::cout << "Meow meow!" << std::endl;
}
