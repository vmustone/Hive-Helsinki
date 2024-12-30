#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* wrongA = new WrongAnimal();
	const WrongCat* wrongC = new WrongCat();
	std::cout << wrongA->getType() << " " << std::endl;
	std::cout << wrongC->getType() << " " << std::endl;
	wrongA->makeSound();
	wrongC->makeSound();

	delete wrongA;
	delete wrongC;

	return 0;
}