/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: villemustonen <villemustonen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:42:10 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/15 07:27:59 by villemuston      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap {
    protected:
        std::string _Name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
    
    public:
        ClapTrap(std::string    name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& tmp);
        ClapTrap& operator=(const ClapTrap& tmp);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};
#endif