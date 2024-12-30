/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:29:20 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/10 02:04:10 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	_value;
		static const int _fractional_bits = 8;
		
	public:
		Fixed( void );
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& other);
		~Fixed();
		
		int		getRawBits( void )const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		Fixed&	operator<<(const Fixed& object);
		Fixed&	operator=(const Fixed& object);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif