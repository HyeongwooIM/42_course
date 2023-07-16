#include "HumanB.hpp"

void HumanB::attack() {
	if (_weapon)
	{
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
		return ;
	}
	std::cout << _name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

HumanB::HumanB(std::string name):_name(name), _weapon(NULL){};