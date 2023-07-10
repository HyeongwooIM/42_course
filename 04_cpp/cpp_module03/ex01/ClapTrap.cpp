#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(HP), _energyPoints(ENERGY),_attackDamage(ATTACK){
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
	_hitPoints += amount;
	std::cout << _name << " is repaired " << amount << " points of health!" << std::endl;
}

unsigned int ClapTrap::getAttackDamage(void) const {
	return _attackDamage;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return _energyPoints;
}

unsigned int ClapTrap::getHitPoints(void) const {
	return _hitPoints;
}

void ClapTrap::printStatus(void) const{
	std::cout << _name << " status" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "HitPoints : " << _hitPoints << std::endl;
	std::cout << "AtaackDamage : " << _attackDamage << std::endl;
	std::cout << "EnergyPoints : " << _energyPoints << std::endl;
	std::cout << "------------------------" << std::endl;
}