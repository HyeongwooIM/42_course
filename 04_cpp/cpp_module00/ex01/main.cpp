#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (1)
	{
		std::cout<<"커맨드를 입력해주세요(ADD / SEARCH / EXIT) : ";
		std::getline(std::cin, cmd);
		if (std::cin.eof() || std::cin.fail())
			break ;
		if (!cmd.compare("ADD"))
			phoneBook.commandAdd();
		else if (!cmd.compare("SEARCH"))
			phoneBook.commandSearch();
		else if (!cmd.compare("EXIT"))
			phoneBook.commandExit();
		else
			std::cout << "Try Again" << std::endl;
		if (std::cin.eof() || std::cin.fail())
			break ;
		std::cin.clear();
	}
	return 0;
}
