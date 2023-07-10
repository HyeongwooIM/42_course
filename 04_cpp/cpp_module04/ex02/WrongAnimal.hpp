#ifndef WORNGANIMAL_HPP
# define WORNGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal(void);
		WrongAnimal& operator=(WrongAnimal const &rhs);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif