#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::Zombie(): _name("default") {}

Zombie::~Zombie()
{
	std::cout << _name << " destructor called" << std::endl;
}