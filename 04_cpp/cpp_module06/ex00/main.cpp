#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	Convert c(argv[1]);
	c.printAll();
	return 0;
}
