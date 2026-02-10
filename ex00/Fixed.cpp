#include "Fixed.hpp"
#include <iostream>

// Fixed a;
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

// Yeni bir nesne, var olan bir nesneden kopyalanarak oluşturulurken çağrılır: Fixed b(a);
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	// Burada "Copy Assignment Operator" fonksiyonunu çağırarak işi ona yıkıyoruz.
	// Bu sayede kopyalama mantığını tek bir yerde (operator= içinde) tutmuş oluyoruz.
	*this = other;
	//copy assignment op olmasa da aynı şeyi yapacaktık.
	// operator= çağırmadan, doğrudan değeri alıp koyuyoruz.
    //this->_fixedPointValue = other.getRawBits();
}

// Zaten var olan iki nesne eşitlenirken çağrılır: b = a; Yeni nesne oluşturmuyor
Fixed &Fixed::operator=(const Fixed &other)
{

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// Diğer nesnenin ham değerini alıp kendime yazıyorum.
		this->_fixedPointValue = other.getRawBits();
		this->a = other.a;
	}
	// Zincirleme atama yapabilmek için (a = b = c) nesnenin kendisini döndürüyoruz
	return (*this);
}

// Nesne silinirken scope dışına çıkarken ya da fonk sonunda çağrılır.
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
