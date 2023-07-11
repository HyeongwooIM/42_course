#include "Dog.hpp"

Dog::Dog():Animal(), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog const &src):Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = src._type;
}

Dog& Dog::operator=(Dog const &rhs)
{
	std::cout << "Cat copy assignment called" << std::endl;
		if (this != &rhs) {
		_type = rhs._type;
		*_brain = *rhs._brain;
		// _brain = rhs._brain;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog make sound : meow" << std::endl;
}