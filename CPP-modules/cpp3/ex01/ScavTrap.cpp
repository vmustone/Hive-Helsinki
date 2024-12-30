/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 03:37:07 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/15 08:05:58 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Scavtrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scavtrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& tmp) : ClapTrap(tmp) {
	std::cout << "Scavtrap copy constructor called" << std::endl;
}

ScavTrap	ScavTrap::operator=(const ScavTrap& tmp) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &tmp)
    {
        this->_Name = tmp._Name;
        this->_hitPoints = tmp._hitPoints;
        this->_energyPoints = tmp._energyPoints;
        this->_attackDamage = tmp._attackDamage;
    }
    return *this;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "Scavtrap " << _Name << " has not enough energy points to attack" << std::endl;
	else {	
		std::cout << "Scavtrap " << _Name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints = _energyPoints - 1;
	}
}