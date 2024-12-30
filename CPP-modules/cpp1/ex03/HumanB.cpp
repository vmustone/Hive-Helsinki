/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:28:07 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 12:19:21 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
	_gun = NULL;
}
HumanB::~HumanB() {
}

void	HumanB::attack() {
	if (_gun != NULL && _gun->getType() != "") 
		std::cout << _name << " attacks with their " << _gun->getType() << std::endl;
	else
		std::cout << _name << " attacks with their bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon& type) {
	_gun = &type;
}