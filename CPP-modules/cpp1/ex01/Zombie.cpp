/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:13:01 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 11:30:31 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	_name = "";
}

Zombie::~Zombie() {
}

void	Zombie::setName(std::string newName) {
	_name = newName;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}