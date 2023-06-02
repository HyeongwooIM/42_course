#include "Zombie.hpp"

Zombie* HordeZombie( int N, std::string name )
{
	Zombie* HordeZombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		HordeZombie[i].setName(name);
	return (HordeZombie);
}