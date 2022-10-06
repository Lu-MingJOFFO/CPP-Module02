/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:17 by ljoffo            #+#    #+#             */
/*   Updated: 2022/05/30 16:00:01 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _number(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

 Fixed & Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	_number = rhs._number;
	//_number = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(int const nb_int)
{
	//std::cout << "Int constructor called" << std::endl;
	_number = nb_int << _bits;
}

Fixed::Fixed(float const nb_float)
{
	//std::cout << "Float constructor called" << std::endl;
	_number = roundf(nb_float * (1 << _bits));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return (this->_number > rhs._number);
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return (this->_number < rhs._number);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_number >= rhs._number);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_number <= rhs._number);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return (this->_number == rhs._number);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_number != rhs._number);
}

Fixed Fixed::operator+(Fixed const & rhs)
{
	/*Fixed	result;

	result._number = this->_number + rhs._number;
	return result;*/
	return Fixed(this->_number + rhs._number);
}
Fixed Fixed::operator-(Fixed const & rhs)
{
	Fixed	result;

	result.setRawBits(this->_number - rhs._number);
	return result;
}
Fixed Fixed::operator*(Fixed const & rhs)
{
	Fixed	result;

	result._number = this->_number * (rhs._number / (1 << _bits));
	return result;
}

Fixed Fixed::operator/(Fixed const & rhs)
{
	Fixed	result;

	result._number = this->_number / (rhs.getRawBits() / (1 << _bits));
	return result;
}

Fixed & Fixed::operator++(void)
{
	++_number;
	return *this;
}
		
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_number++;
	return temp;
}
		
Fixed & Fixed::operator--(void)
{
	--_number;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_number--;
	return temp;
}

Fixed Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs > rhs)
		return rhs;
	else
		return lhs;
}	

Fixed Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs > rhs)
		return rhs;
	else
		return lhs;
}

Fixed Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (lhs < rhs)
		return rhs;
	else
		return lhs;
}	

Fixed Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs < rhs)
		return rhs;
	else
		return lhs;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _number;
}

void Fixed::setRawBits(int const raw)
{
	_number = raw;
}

float Fixed::toFloat(void) const
{
	float toF = (float)_number / (1 << _bits);
	return toF;
}

int Fixed::toInt(void) const
{
	int toI = _number >> _bits;
	return toI;
}

/// out of Fixed class 

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}