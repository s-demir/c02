#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // roundf için gerekli

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int value); //intle verirsen bu
        Fixed(const float value); //floatla verirsen bu
        Fixed(const Fixed& other); //nesneyle çağırırsan bu
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif