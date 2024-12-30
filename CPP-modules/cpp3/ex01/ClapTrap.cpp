/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:41:47 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/15 06:54:45 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Claptrap constructor called" << std::endl;
	_Name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap destuctor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& tmp) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = tmp;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& tmp)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &tmp)
    {
        _Name = tmp._Name;
        _hitPoints = tmp._hitPoints;
        _energyPoints = tmp._energyPoints;
        _attackDamage = tmp._attackDamage;
    }
    return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "ClapTrap " << _Name << " has not enough energy points to attack" << std::endl;
	else {	
		std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints = _energyPoints - 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _Name << " died" << std::endl;
	} else {
		std::cout << "ClapTrap " << _Name << " takes " << amount << " points of damage" << std::endl;
		_hitPoints = _hitPoints - amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0 || _hitPoints <= 0)
		std::cout << "ClapTrap " << _Name << " has not enough " << amount << "energy points to repair" << std::endl;
	else {
		std::cout << "ClapTrap " << _Name << " repairs " << amount << " hitpoints" << std::endl;
		_hitPoints = _hitPoints + amount;
		_energyPoints = _energyPoints - 1;
	}
}