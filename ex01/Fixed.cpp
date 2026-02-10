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










Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    // Sayıyı 8 bit sola kaydır (x 256 yapmakla aynıdır ama daha hızlıdır)
    this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    // 1. Sayıyı 256 ile çarp.
    // 2. roundf ile en yakın tamsayıya yuvarla.
    // 3. (int) ile cast et ve sakla.
    this->_fixedPointValue = (int)roundf(value * 256);
}

//İçindeki ham değeri gerçek float'a çevirir
float Fixed::toFloat(void) const
{
    // Ham değeri 256.0'a bölüyoruz .ünkü buna çarpmıştık
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

// İçindeki ham değeri! gerçek int'e çevirir
int Fixed::toInt(void) const
{
    // Ham değeri 256'ya bölüyoruz (veya 8 bit sağa kaydırıyoruz).
    return this->_fixedPointValue >> _fractionalBits;
}

// 5. Stream Operator Overload (cout << fixed_objesi) direkt böyle verebilcez
// Bu fonksiyon sınıfın üyesi değil global scope
std::ostream & operator<<( std::ostream & obj, Fixed const & i )
{
    // Ekrana nesnenin float karşılığını basıyoruz
    obj << i.toFloat();
    return obj;
}
