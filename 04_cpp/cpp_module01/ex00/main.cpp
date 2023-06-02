#include "Zombie.hpp"

void main2()
{
	Zombie	zombieStack = Zombie("stackZombie");
	Zombie	*zombieHeap = new Zombie("heapZombie");
	Zombie	*zombieNew = newZombie("newZombie");

	zombieStack.announce();
	zombieHeap->announce();
	zombieNew->announce();
	randomChump("randomChump");
	delete zombieHeap;
	delete zombieNew;
}

int main()
{
	main2();
	system("leaks Zombie");
}