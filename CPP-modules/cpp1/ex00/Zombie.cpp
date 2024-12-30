/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:24:21 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 10:57:24 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	_Name = "";
}

Zombie::~Zombie() {
	std::cout << _Name << "'s Destructor called" << std::endl;
}

void	Zombie::announce() {
	std::cout << _Name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string newName) {
	_Name = newName;
}