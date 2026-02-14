#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

//şimdi. fixed point sayıyı bilgisayarın kolay tutabilmesi için zomlamak
// zom yap 256 ile çarp int olarak sakla
//256 yani 2^8 çünkü ikili sistem

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}

//ekrana basarken de tekrar küçültmemiz lazım
//256yla çarpcaz ama int tipi virgül tutamaz bu yüzden roundf ile yuvarlama yap
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)roundf(value * 256);
}

//çünkü int tipine çevirirken 256yla çarpmıştık
//roundf yaptığımız için değer kaybı olacak
float Fixed::toFloat(void) const
{
	return (this->_fixedPointValue / 256.0f);
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &left, Fixed const &right)
{
	left << right.toFloat(); //tofloat ile zoom out yapıyourz int yerine ki veri kaybetme
	return (left);
}
