#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void main2()
{
	FragTrap trap1("Trap1");
	ScavTrap trap2("Trap2");

	std::cout << std::endl;

	trap1.attack("Trap2");
	trap2.takeDamage(trap1.getAttackDamage());
	trap2.beRepaired(10);
	trap1.printStatus();
	trap2.printStatus();
	std::cout << std::endl;
	trap1.attack("Trap2");
	trap2.guardGate();
	std::cout << std::endl;
	trap1.highFivesGuys();
	trap1.printStatus();
	trap2.printStatus();
	std::cout << std::endl;
}

int	main()
{
	main2();
	system("leaks FragTrap");
	return 0;
}
