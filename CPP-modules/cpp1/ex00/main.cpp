/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:04:57 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 11:10:47 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *zombie;
	std::string input;

	std::cout << "New zombie has born, name it: ";
	std::getline(std::cin, input);
	try {
		zombie = newZombie(input);
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Issue allocating zombie\n";
		return 1;
	}
	zombie->announce();
	delete zombie;

	std::cout << "Another zombie has born, name it: ";
	std::getline(std::cin, input);
	randomChump(input);
	return 0;
}