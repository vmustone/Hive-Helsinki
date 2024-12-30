#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete materias[i];
}

MateriaSource::MateriaSource(const	MateriaSource& other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		materias[i] = other.materias[i];
}

MateriaSource& MateriaSource::operator=(const	MateriaSource& other) {
	std::cout << "MateriaSource assignation operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++)
            materias[i] = other.materias[i];
    }
    return *this;
}

AMateria* MateriaSource::getMateria( std::string const & type ) {
    for (int i = 0; i < 4; i++)
        if (materias[i] && materias[i]->getType() == type)
            return materias[i];
    return NULL;
}

void    MateriaSource::learnMateria( AMateria* m ) {
    for (int i = 0; i < 4; i++) {
        if (materias[i] == NULL) {
            materias[i] = m;
            return;
        }
	}
}

AMateria*   MateriaSource::createMateria( std::string const& type ) {
    for ( int i = 0; i < 4; i++ )
        if ( materias[i] && materias[i]->getType() == type ) {
			std::cout << "Materia " << type << " created" << std::endl;
            return materias[i]->clone();
		}
	std::cout << "couldn't create " << type << " materia" << std::endl;
    return NULL;
}