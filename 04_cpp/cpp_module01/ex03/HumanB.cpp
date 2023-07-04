#include "HumanB.hpp"

void HumanB::attack() {
	if (this->_weapon)
	{
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
		return ;
	}
	std::cout << this->_name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name):_name(name), _weapon(NULL){};