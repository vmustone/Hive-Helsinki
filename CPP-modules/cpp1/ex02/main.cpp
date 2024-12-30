/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:05:50 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 08:19:36 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string* brainPTR = &brain;
	std::string& brainREF = brain;

	std::cout << &brain << std::endl;
	std::cout << brainPTR << std::endl;
	std::cout << &brainREF << std::endl;

	std::cout << brain << std::endl;
	std::cout << *brainPTR << std::endl;
	std::cout << brainREF << std::endl;

	return 0;
}