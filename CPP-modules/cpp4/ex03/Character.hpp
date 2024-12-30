#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _Name;
		AMateria* _inv[4];
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& other);
		void    equip( AMateria* m );
		void    unequip( int idx );
		void    use( int idx, ICharacter& target );
		std::string const&	getName() const;
		AMateria*	getInv(int idx) const;
};

#endif