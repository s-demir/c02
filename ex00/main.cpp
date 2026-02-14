#include "Fixed.hpp"

int	main( void )
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}


// int main()
// {
//     Fixed fixA;
//     Fixed fixB;
//     Fixed fixC;

//     fixA.a = 5;
//     fixB.a = 10;
//     fixC.a = 15;
//     fixB = fixA = fixC;
//     std::cout << fixB.a << std::endl;
//     std::cout << fixA.a << std::endl;
//     std::cout << fixC.a << std::endl;

//     return (0);
// }
