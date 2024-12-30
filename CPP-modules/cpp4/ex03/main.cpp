#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());

	ICharacter* me = new Character("Gandalf");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	AMateria* tmp2;
	tmp2 = src2->createMateria("moi");
	bob->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	bob->equip(tmp2);
	tmp2 = src2->createMateria("ice");
	bob->equip(tmp2);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	
	tmp = me->getInv(0);
	me->unequip(0);
	me->use(0, *bob);
	delete tmp;

	tmp = me->getInv(1);
	me->unequip(1);
	delete tmp;
	
	me->unequip(2);

	tmp2 = bob->getInv(0);
	bob->unequip(0);
	delete tmp2;

	tmp2 = bob->getInv(1);
	bob->unequip(1);
	delete tmp2;

	tmp2 = bob->getInv(3);
	bob->unequip(2);
	delete tmp2;

	delete bob;
	delete me;
	delete src;
	delete src2;

	return 0;
}