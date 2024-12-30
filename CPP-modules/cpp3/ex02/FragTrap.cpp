/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:16:43 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/15 08:58:21 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Fragtrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "Fragtrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& tmp) : ClapTrap(tmp) {
	std::cout << "Fragtrap copy constructor called" << std::endl;
}

FragTrap FragTrap::operator=(const FragTrap& tmp) {
	std::cout << "Fragtrap assignation constructor called" << std::endl;
	if (this != &tmp) {
		this->_Name = tmp._Name;
		this->_hitPoints = tmp._hitPoints;
		this->_energyPoints = tmp._energyPoints;
		this->_attackDamage = tmp._attackDamage;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << _Name << " Gives high fives" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "Fragtrap " << _Name << " has not enough energy points to attack" << std::endl;
	else {	
		std::cout << "Fragtrap " << _Name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints = _energyPoints - 1;
	}
}