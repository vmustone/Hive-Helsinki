/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:28:13 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 12:19:08 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : _name(name), _gun(type) {
}

HumanA::~HumanA() {
}

void	HumanA::attack() {
	if (_gun.getType() != "")
		std::cout << _name << " attacks with their " << _gun.getType() << std::endl;
	else
		std::cout << _name << " attacks with their bare hands" << std::endl;
}