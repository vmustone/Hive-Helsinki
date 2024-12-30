/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:45:24 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/02 23:53:31 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	index = 0;
}

string PhoneBook::removeSpaces(string input) {
	int start = 0;
    int end = input.length() - 1;

    while (start < input.length() && isspace(input[start])) {
        start++;
    }

    while (end > start && isspace(input[end])) {
        end--;
    }

    return input.substr(start, end - start + 1);
}


bool PhoneBook::isNumeric(string str) {
   int i = 0;
   
   while (str[i]) {
        if (!isdigit(str[i])) {
            return false;
        }
		i++;
    }

    return true;
}

string	PhoneBook::addContactField(string prompt) {
    string input;
    
	cout << prompt;
    while (true) {
        getline(cin, input);
        input = removeSpaces(input);

        if (cin.eof()) {
			cout << endl;
            cout << "Error, end of file" << endl;
            exit(EXIT_FAILURE);
        }

        if (!input.empty())
            break;
		else
			cout << "Please, try again: ";
    }
	return input;
}

void	PhoneBook::addContact() {
	string valid_input;
    
	valid_input = addContactField("Enter first name: ");
	contacts[index % 8].SetFirstName(valid_input);

	valid_input = addContactField("Enter last name: ");
	contacts[index % 8].SetLastName(valid_input);

	valid_input = addContactField("Enter nickname: ");
	contacts[index % 8].SetNickName(valid_input);

	valid_input = addContactField("Enter phone number: ");
	contacts[index % 8].SetPhoneNumber(valid_input);

	valid_input = addContactField("Enter darkest secret: ");
	contacts[index % 8].SetDarkestSecret(valid_input);	
    index++;
}

void	PhoneBook::displayColumn() {
	int size = index;

	if (size > 8)
		size = 8;

	if (contacts[0].GetFirstName() == ""){
		cout << "Phonebook is empty. Add contact." <<  endl;
		return;
	}

	cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << endl;
	
	for (int i = 0; (i < size); i++){
		cout << setw(10) << i;

		if (contacts[i].GetFirstName().length() > 10)
			cout << "|" << setw(10) << contacts[i].GetFirstName().substr(0, 9) + '.';
		else
			cout << "|" << setw(10) << contacts[i].GetFirstName().substr(0, 10);

		if (contacts[i].GetLastName().length() > 10)
			cout << "|" << setw(10) << contacts[i].GetLastName().substr(0, 9) + '.';
		else
			cout << "|" << setw(10) << contacts[i].GetLastName().substr(0, 10);

		if (contacts[i].GetNickName().length() > 10)
			cout << "|" << setw(10) << contacts[i].GetNickName().substr(0, 9) + '.';
		else
			cout << "|" << setw(10) << contacts[i].GetNickName().substr(0, 10);
			
		cout << endl;
	}
}

int	PhoneBook::inputCheck(string input) {
	int id;
	while (true) {
		getline(cin, input);
		if (cin.eof()){
			cout << endl;
			cout << "Error, end of file" << endl;
			exit(EXIT_FAILURE);
		}

		while (input.empty() || !isNumeric(input)) {
			if (cin.eof()) {
				cout << endl;
				cout << "Error, end of file" << endl;
				exit(EXIT_FAILURE);
			}
        	cout << "Invalid input. Please enter a valid index and try again: ";
			getline(cin, input);
    	}

		id = stoi(input, nullptr);
		
		if (id < 0 || id > 7 || contacts[id].GetFirstName() == "") {
			cout << "Invalid input. Please enter a valid index and try again: ";
			}
		
		else
			break;
	}
	return id;
}

void	PhoneBook::displayContacts(){
	string input;
	int id;
	
	if (contacts[0].GetFirstName() == ""){
		cout << "Phonebook is empty. Add contact." <<  endl;
		return;
	}

	displayColumn();

	cout << "Enter index: ";
	
	id = inputCheck(input);
	
	cout << "First name: " << contacts[id].GetFirstName() << endl;
	cout << "Last name: " << contacts[id].GetLastName() << endl;
	cout << "Nickname: " << contacts[id].GetNickName() << endl;
	cout << "Phonenumber: " << contacts[id].GetPhoneNumber() << endl;
	cout << "Darkest secret: " << contacts[id].GetDarkestSecret() << endl;
}
