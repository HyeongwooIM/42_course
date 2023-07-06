#include "ScavTrap.hpp"

int	main()
{
	ScavTrap trap1("A");
	ScavTrap trap2("B");
	ClapTrap * trap3 = new ScavTrap("C");

	trap3->attack("A");
	std::cout << std::endl;
	trap1.attack("B");
	trap2.takeDamage(trap1.getAttackDamage());
	trap2.beRepaired(10);
	std::cout << std::endl;
	trap1.attack("B");
	trap2.takeDamage(trap1.getAttackDamage());
	trap2.beRepaired(10);
	std::cout << std::endl;
	trap1.guardGate();
	std::cout << std::endl;
	return 0;
}
