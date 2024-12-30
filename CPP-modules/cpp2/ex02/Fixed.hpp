/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:25:35 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/10 02:47:08 by vmustone         ###   ########.fr       */
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
		
		bool	operator<( const Fixed& object ) const;
		bool	operator>( const Fixed& object ) const;
		bool	operator<=( const Fixed& object ) const;
		bool	operator>=( const Fixed& object ) const;
		bool	operator==( const Fixed& object ) const;
		bool	operator!=( const Fixed& object ) const;

		Fixed	operator+( const Fixed& object ) const;
		Fixed	operator-( const Fixed& object ) const;
		Fixed	operator*( const Fixed& object ) const;
		Fixed	operator/( const Fixed& object ) const;
		
		Fixed&	operator++( void );
		Fixed&	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		Fixed&	operator<<( const Fixed& object );
		Fixed&	operator=( const Fixed& object );
		
		static Fixed&	max( Fixed& a, Fixed& b );
		static Fixed&	min( Fixed& a, Fixed& b );
		static Fixed const& max( const Fixed& a, const Fixed& b );
		static Fixed const& min( const Fixed& a, const Fixed& b );
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif