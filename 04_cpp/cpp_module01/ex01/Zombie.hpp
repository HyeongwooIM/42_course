#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		void	announce(void);
		void	setName(std::string name);
		Zombie(std::string name);
		Zombie();
		~Zombie();
};

Zombie* HordeZombie( int N, std::string name );

# endif
