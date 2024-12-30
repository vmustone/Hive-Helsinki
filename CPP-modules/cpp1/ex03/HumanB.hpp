/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:28:03 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 11:45:56 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB {
	private:
		Weapon*	_gun;
		std::string	_name;
	public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon& type);
};

#endif