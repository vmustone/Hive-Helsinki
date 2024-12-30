/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:21:27 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 10:56:10 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
	private:
		std::string _Name;
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(std::string newName);
};

Zombie *newZombie( std::string name );
void	randomChump( std::string name );
#endif