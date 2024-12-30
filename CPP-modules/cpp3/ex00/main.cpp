/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:40:04 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/14 03:24:08 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap	clapA("Matti");
	ClapTrap	clapB("Teppo");
	ClapTrap	clapC(clapA);
	ClapTrap	clapD("juhani");
	clapA.attack("Teppo");
	clapB.attack("Matti");
	clapB.takeDamage(5);
	clapA.takeDamage(10);
	clapB.beRepaired(5);

	return 0;
}