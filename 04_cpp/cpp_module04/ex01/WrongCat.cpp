#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = src._type;
}

WrongCat& WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat make sound : meow" << std::endl;
}
