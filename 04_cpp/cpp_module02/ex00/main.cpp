#include "Fixed.hpp"

void main2(void) {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl; 
}

int main(void) {
	main2();
	system("leaks Fixed");
}