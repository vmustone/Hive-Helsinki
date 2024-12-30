/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:38:35 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/02 23:49:58 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

using std::cin;
using std::getline;
using std::cout;
using std::setw;
using std::endl;

class PhoneBook{
private:
	Contact contacts[8];
	int	index;
	
public:
	PhoneBook();
	void	addContact();
	void	displayContacts();
	void	displayColumn();
	int		inputCheck(string input);
	bool 	isNumeric(string str);
	string	removeSpaces(string input);
	string	addContactField(string prompt);
};
#endif