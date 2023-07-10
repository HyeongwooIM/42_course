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
		void makeSound(void) const;
};

#endif