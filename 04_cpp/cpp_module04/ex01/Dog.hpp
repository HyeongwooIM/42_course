#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog:public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();
		Dog& operator=(Dog const &rhs);

		void makeSound() const;
};
#endif