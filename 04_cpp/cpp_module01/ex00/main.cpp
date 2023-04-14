#include "Zombie.hpp"

void makeHeapZ(void) {
	Zombie *newZ = newZombie("heapZ");
	newZ->announce();
	delete newZ;
}