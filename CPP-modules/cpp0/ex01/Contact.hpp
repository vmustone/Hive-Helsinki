/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:32:46 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/02 22:08:16 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

using std::string;

class Contact{
private:
string FirstName;
string LastName;
string NickName;
string PhoneNumber;
string DarkestSecret;

public:
	Contact();
	string	GetFirstName(void)const;
	string	GetLastName(void)const;
	string	GetNickName(void)const;
	string	GetPhoneNumber(void)const;
	string	GetDarkestSecret(void)const;

	void	SetFirstName(std::string input);
	void	SetLastName(std::string input);
	void	SetNickName(std::string input);
	void	SetPhoneNumber(std::string	input);
	void	SetDarkestSecret(std::string input);
};
#endif