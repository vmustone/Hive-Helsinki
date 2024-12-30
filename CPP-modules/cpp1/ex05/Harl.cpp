/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:51:48 by villemuston       #+#    #+#             */
/*   Updated: 2023/10/16 11:31:19 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug( void ) {
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info( void ) {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put \
enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for \
years whereas you started working here since last month." << std::endl;
}

void    Harl::error( void ) {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string choice[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    t_func funcs[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == choice[i])
        {
            (this->*funcs[i])();
            return ;
        }
    }
    std::cout << "Harl doesn't know how to complain at " << level << " level." << std::endl;
}
