#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		enum {
			HP = 10,
			ENERGY = 10,
			ATTACK = 0
		};

	public:
		ClapTrap();
		ClapTrap(std::string	name);
		ClapTrap(const ClapTrap &src);
		virtual ~ClapTrap();

		ClapTrap		&operator=(const ClapTrap &rhs);

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getAttackDamage(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		void			printStatus(void) const;
};

# endif