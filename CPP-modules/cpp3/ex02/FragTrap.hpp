/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:11:13 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/15 08:58:11 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap& tmp);
		FragTrap operator=(const FragTrap& tmp);
		void	highFivesGuys(void);
		void	attack(const std::string& target);	
};
#endif