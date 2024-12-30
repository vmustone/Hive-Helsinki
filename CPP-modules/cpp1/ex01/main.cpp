/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:07:39 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 11:26:44 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	size_t num_zombies;
	std::string name_zombies;
	Zombie *newZ;

	std::cout << "Enter number of zombies and name for zombies: ";
	std::cin >> num_zombies >> name_zombies;
	try {
		newZ = zombieHorde(num_zombies, name_zombies);
	} catch (const std::bad_alloc& e) {
		std::cout << "Issue allocating zombie\n";
		return 1;
	}
	for (int i = 0; i < num_zombies; i++) {
		newZ[i].announce();
	}
	delete[] newZ;
	return 0;
}