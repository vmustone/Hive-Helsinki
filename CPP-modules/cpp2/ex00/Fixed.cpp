/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:01:50 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/10 01:47:11 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object) {
	std::cout << "Copy constructor called" << std::endl;
	operator=(object);
}

Fixed&	Fixed::operator=(const Fixed& object) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object)
		_value = object.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void )const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits( int const raw ) {
		_value = raw;
}