#include "Fixed.hpp"

int main()
{
    Fixed fixA;
    Fixed fixB;
    Fixed fixC;

    fixA.a = 5;
    fixB.a = 10;
    fixC.a = 15;
    fixB = fixA = fixC;
    fixB.a = fixA.a;
    std::cout << fixB.a << std::endl;
    std::cout << fixA.a << std::endl;
    std::cout << fixC.a << std::endl;

    return (0);
}
