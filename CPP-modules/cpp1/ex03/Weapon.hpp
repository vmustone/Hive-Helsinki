/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:28:24 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 11:36:44 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
	private:
		std::string _type;
	public:
		Weapon(std::string weapon);
		~Weapon();
		const std::string&	getType();
		void	setType(std::string name);
};

#endif