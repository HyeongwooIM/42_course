#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src){
	*this = src;
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_attackDamage = rhs._attackDamage;
		_energyPoints = rhs._energyPoints;
	}
	return *this;
}

void ScavTrap::guardGate() {
	if (!_hitPoints){
		std::cout << "ScavTrap " << _name << " is died" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!_hitPoints){
		std::cout << "ScavTrap " << _name << " is dead." << std::endl;
		return ;
	}
	if (!_energyPoints){
		std::cout << "ScavTrap " << _name << " has no energy" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
