#include <iostream>
class c
{
private:

public:

int a=3;


int&  fun()
{
	return a;
}
};


int main()
{
	c b;
	std::cout<<b.a<<std::endl;
	b.fun()=2;

	std::cout<<b.fun()<<std::endl;
}