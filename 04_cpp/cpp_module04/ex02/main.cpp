#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

		for (int i = 0; i < 4; i++)
			std::cout << animals[i]->getType() << std::endl;

		for (int i = 0; i < 4; i++)
			delete animals[i];
	}
	{
		// Animal animal; // error: cannot declare variable 'animal' to be of abstract type 'AAnimal'
	}

	return 0;
}