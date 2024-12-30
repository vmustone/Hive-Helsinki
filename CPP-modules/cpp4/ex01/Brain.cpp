#include "Brain.hpp"

Brain::Brain() {
	std::cout << "brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "brain assignation operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}