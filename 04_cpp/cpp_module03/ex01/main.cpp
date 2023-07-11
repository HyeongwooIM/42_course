#include "ScavTrap.hpp"

void main2()
{
	ScavTrap trap1("A");
	ScavTrap trap2("B");
	ClapTrap * trap3 = new ScavTrap("C");

	trap3->attack("A");
	std::cout << std::endl;
	trap1.attack("B");
	trap2.takeDamage(trap1.getAttackDamage());
	trap2.beRepaired(1000);
	std::cout << std::endl;
	trap1.printStatus();
	trap2.printStatus();
	std::cout << std::endl;
	trap1.attack("B");
	trap2.takeDamage(trap1.getAttackDamage());
	trap2.beRepaired(10);
	std::cout << std::endl;
	trap1.guardGate();
	trap1.printStatus();
	trap2.printStatus();
	std::cout << std::endl;
	delete trap3;
}

int	main()
{
	main2();
	system("leaks ScavTrap");
	return 0;
}
