#include "Zombie.hpp"

void main2()
{
	Zombie* zombie = HordeZombie(5, "zombie");

	for (int i = 0; i < 5; i++)
		zombie[i].announce();
	delete[] zombie;
}

int main()
{
	main2();
	system("leaks Zombie");
}