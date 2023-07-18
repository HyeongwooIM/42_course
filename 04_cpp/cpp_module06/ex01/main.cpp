#include "Serializer.hpp"
#include <iostream>

int main() {
	Data a = {'h', 10, 5.5f, 5.5};
	uintptr_t uintptr;

	uintptr = Serializer::serialize(&a);
	std::cout << uintptr << std::endl;
	std::cout << Serializer::deserialize(uintptr) << std::endl;
	std::cout << &a << std::endl;

	std::cout << (&a == Serializer::deserialize(uintptr) ? "equal!" : "not equal") << std::endl;

}