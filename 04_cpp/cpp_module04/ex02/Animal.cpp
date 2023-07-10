#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src):_type(src._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal make sound : ..." << std::endl;
}
std::string Animal::getType() const
{
	return _type;
}