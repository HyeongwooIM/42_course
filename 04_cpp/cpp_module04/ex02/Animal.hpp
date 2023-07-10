#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();
		Animal& operator=(Animal const &rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif