/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:29:23 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/10 03:06:13 by vmustone         ###   ########.fr       */
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

Fixed::Fixed( const int n ) {
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractional_bits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
    _value = roundf(f * (1 << _fractional_bits));
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
	return _value;
}

void	Fixed::setRawBits( int const raw ) {
		_value = raw;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed) {
    output << fixed.toFloat();
    return output;
}

float Fixed::toFloat( void ) const {
	float scaled_value = static_cast<float>(_value) / (1 << _fractional_bits);
    return scaled_value;
}

int Fixed::toInt( void ) const {
    int result = _value >> _fractional_bits;
    return result;
}