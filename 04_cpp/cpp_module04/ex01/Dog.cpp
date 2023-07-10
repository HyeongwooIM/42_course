#include "Dog.hpp"

Dog::Dog():Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog const &src):Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = src._type;
}

Dog& Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog make sound : meow" << std::endl;
}