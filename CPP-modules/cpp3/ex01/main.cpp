/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:40:04 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/15 08:09:17 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ScavTrap	scavA("Matti");
	ScavTrap	scavB("Teppo");
	ScavTrap	scavC = scavA;
	scavA.attack("Teppo");
	scavB.takeDamage(50);
	scavB.beRepaired(100);
	scavA.guardGate();

	return 0;
}