#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clapTrap1("ClapTrap1");
	ClapTrap clapTrap2("ClapTrap2");

	clapTrap2.attack("ClapTrap1");
	clapTrap1.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.attack("ClapTrap1");
	clapTrap1.takeDamage(clapTrap2.getAttackDamage());
	clapTrap1.printStatus();
	clapTrap2.printStatus();
	clapTrap1.beRepaired(1);
	for (int i = 0; i < 10; i++) {
		clapTrap1.attack("ClapTrap2");
	}
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	clapTrap2.beRepaired(1);
	clapTrap1.attack("ClapTrap2");
	clapTrap1.printStatus();
	clapTrap2.printStatus();
	return 0;
}