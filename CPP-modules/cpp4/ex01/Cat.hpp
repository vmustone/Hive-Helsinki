#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
private:
	Brain* _brain;
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& other);
	Cat&	operator=(const Cat& other);
	void	makeSound() const;
};

#endif