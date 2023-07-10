#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	_hitPoints = HP;
	_energyPoints = ENERGY;
	_attackDamage = ATTACK;
	std::cout << "FragTrap " << _name << " constructor created" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	_hitPoints = HP;
	_energyPoints = ENERGY;
	_attackDamage = ATTACK;
	std::cout << "FragTrap " << _name << " constructor created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) {
	*this = src;
	std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs){
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	if (!_hitPoints){
		std::cout << "FragTrap " << _name << " died" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " high fives guys *^^*" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (!_hitPoints){
		std::cout << "FragTrap " << _name << " is dead." << std::endl;
		return ;
	}
	if (!_energyPoints){
		std::cout << "FragTrap " << _name << " has no energy" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}