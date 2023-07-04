#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return (0);
	Zombie *zombieHorde = new Zombie[N];
	std::stringstream	number;
	for (int i = 0; i < N; i++)
	{
		number.str(std::string());;
		number << i;
		zombieHorde[i].setName(name + number.str());
	}
	return (zombieHorde);
}