/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:01:53 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/10 02:04:53 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& object);
		~Fixed();
		
		int		getRawBits( void )const;
		void	setRawBits( int const raw );

		Fixed&	operator=(const Fixed& object);

};
#endif