/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:28:21 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 11:36:04 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) {
	setType(weapon);
}

Weapon::~Weapon() {
}

const std::string&	Weapon::getType() {
	return _type;
}

void	Weapon::setType(std::string name) {
	_type = name;
}