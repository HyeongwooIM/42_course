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

//	Data* array = new Data[10];
//	int index = 5;
//	Data* ptr = &array[index]; // get a pointer to the 6th object in the array
//	std::cout << "ptr: " << &ptr << std::endl;
//	uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
//	std::cout << "addr: " << addr << std::endl;
//	std::cout << "sizeof(Data): " << sizeof(Data) << std::endl;
//	uintptr_t nextAddr = addr + sizeof(Data);
//	std::cout << "nextAddr: " << nextAddr << std::endl;
//	Data* nextPtr = reinterpret_cast<Data*>(nextAddr);
//	std::cout << "nextPtr: " << &nextPtr << std::endl;
}