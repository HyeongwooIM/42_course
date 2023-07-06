#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(10),_attackDamage(0){
	std::cout << "ClapTrap " << _name << "constructor created" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10),_attackDamage(0){
	std::cout << "ClapTrap " << _name << " constructor created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
	std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << "ClapTrap " << this->_name << " copy assignment called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!_hitPoints){
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
		return ;
	}
	if (!_energyPoints){
		std::cout << "ClapTrap " << _name << " has no energy" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints){
		std::cout << _name << " is dead." << std::endl;
		return ;
	}
	std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
	if (_hitPoints <= amount){
		_hitPoints = 0;
		std::cout << _name << " is dead." << std::endl;
	}
	else {
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints){
		std::cout << _name << " is dead." << std::endl;
		return ;
	}
	if (!_energyPoints){
		std::cout << _name << " has no energy points!" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	if ( (amount + _hitPoints) >= 10)
		_hitPoints = 10;
	else
		_hitPoints += amount;
	std::cout << _name << " is repaired " << amount << " points of health!" << std::endl;

}

int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}