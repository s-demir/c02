#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << "  1"<< std::endl;
	std::cout << ++a << "  2" << std::endl;
	std::cout << a << "  3" << std::endl;
	std::cout << a++ << "  4" << std::endl;
	std::cout << a << "  5" << std::endl;

	std::cout << b << "  6" << std::endl;

	std::cout << Fixed::max( a, b ) << "  7" << std::endl;

	return (0);
}