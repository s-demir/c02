#include "Fixed.hpp"
#include <iostream>

// 1. Default Constructor (Varsayılan Kurucu)
// Nesne parametresiz oluşturulduğunda çağrılır: Fixed a;
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0; // Değeri 0'a eşitle
}

// 2. Copy Constructor (Kopyalama Kurucusu)
// Yeni bir nesne, var olan bir nesneden kopyalanarak oluşturulurken çağrılır: Fixed b(a);
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;

    // Burada "Copy Assignment Operator" fonksiyonunu çağırarak işi ona yıkıyoruz.
    // Bu sayede kopyalama mantığını tek bir yerde (operator= içinde) tutmuş oluyoruz.
    *this = other;
}

// 3. Copy Assignment Operator (Kopyalama Atama Operatörü)
// Zaten var olan iki nesne eşitlenirken çağrılır: b = a;
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    // Self-Assignment Check (Kendini kendine atama kontrolü)
    // Eğer "a = a" denilirse boşuna işlem yapma.
    if (this != &other)
    {
        // Diğer nesnenin ham değerini alıp kendime yazıyorum.
        this->_fixedPointValue = other.getRawBits();
		this->a = other.a;
    }

    // Zincirleme atama yapabilmek için (a = b = c) nesnenin kendisini döndürüyoruz.
    return *this;
}

// 4. Destructor (Yıkıcı)
// Nesne silinirken (scope dışına çıkarken) çağrılır.
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// --- Yardımcı Fonksiyonlar ---

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    // Bu fonksiyonda çıktı istenmemiş ama gerekirse ekleyebilirsin.
    this->_fixedPointValue = raw;
}