#include "Zombie.hpp"

int main()
{
	Zombie	zombieStack = Zombie("stackZombie");
	Zombie	*zombieHeap = new Zombie("heapZombie");
	Zombie	*zombieNew = newZombie("newZombie");

	zombieStack.announce();
	zombieHeap->announce();
	zombieNew->announce();
	randomChump("randomChump");
	delete zombieHeap;
	atexit("");
}