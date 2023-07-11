#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main2()
{
	{
		Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

		for (int i = 0; i < 4; i++)
			std::cout << animals[i]->getType() << std::endl;

		for (int i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << "123123" << std::endl;
	{
		Dog  *dog1 = new Dog();
		Dog dog2;
		dog2 = *dog1;
		delete dog1;
	}

	return 0;
}

int	main()
{
	main2();
	// system("leaks Animal");
	return 0;
}