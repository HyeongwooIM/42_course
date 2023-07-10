#include "Cat.hpp"

Cat::Cat():Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat const &src):Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = src._type;
}

Cat& Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat make sound : meow" << std::endl;
}