/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:57:28 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/02 21:57:10 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	string	input;
	
	while (true)
	{
		cout << "Enter a command (ADD, SEARCH, EXIT)" << endl;
		getline(cin, input);

		if (cin.eof()){
			cout << "Error, end of file" << endl;
			exit(EXIT_FAILURE);
		}

		if (input == "ADD")
			book.addContact();

		if (input == "SEARCH")
			book.displayContacts();
		
		if (input == "EXIT")
			break;
	}
	return (0);
}