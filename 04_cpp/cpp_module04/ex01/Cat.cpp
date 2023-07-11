#include "Cat.hpp"

Cat::Cat():Animal(), _brain(new Brain())
{
	std::cout << "Cat is born" << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat const &src):Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &rhs) {
		_type = rhs._type;
		*_brain = *rhs._brain;
		// _brain = rhs._brain;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat make sound : meow" << std::endl;
}