/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:40:04 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/15 08:55:25 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ScavTrap	scavA("Matti");

	scavA.attack("Teppo");
	scavA.takeDamage(50);
	scavA.beRepaired(100);
	scavA.guardGate();

	FragTrap	fragA("Teppo");

	fragA.attack("Matti");
	fragA.takeDamage(50);
	fragA.beRepaired(100);
	fragA.highFivesGuys();

	return 0;
}