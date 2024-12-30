/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:44:40 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/02 22:07:44 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	FirstName = "";
	LastName = "";
	NickName = "";
	PhoneNumber = "";
	DarkestSecret = "";
}

std::string	Contact::GetFirstName(void)const{
	return FirstName;
}

std::string	Contact::GetLastName(void)const{
	return LastName;
}

std::string	Contact::GetNickName(void)const{
	return NickName;
}

std::string Contact::GetPhoneNumber(void)const{
	return PhoneNumber;
}

std::string	Contact::GetDarkestSecret(void)const{
	return DarkestSecret;
}

void	Contact::SetFirstName(std::string input){
	FirstName = input;
}

void	Contact::SetLastName(std::string input){
	LastName = input;
}

void	Contact::SetNickName(std::string input){
	NickName = input;
}

void	Contact::SetPhoneNumber(std::string input){
	PhoneNumber = input;
}

void	Contact::SetDarkestSecret(std::string input){
	DarkestSecret = input;
}