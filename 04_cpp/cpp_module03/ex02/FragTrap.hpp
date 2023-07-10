#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap();
		FragTrap(const FragTrap &src);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap &operator=(const FragTrap &rhs);

		void highFivesGuys();
		void attack(const std::string &target);
		enum status{
			HP = 100,
			ENERGY = 100,
			ATTACK = 30
		};
};

# endif