#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main2()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "j is " << j->getType() << " " << std::endl;
	std::cout << "i is " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	WrongAnimal* wrong = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();
	wrong->makeSound();
	wrongCat->makeSound();

	delete wrong;
	delete wrongCat;

	return 0;
}

int	main()
{
	main2();
	system("leaks Animal");
	return 0;
}