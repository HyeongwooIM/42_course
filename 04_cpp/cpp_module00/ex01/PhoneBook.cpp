#include "PhoneBook.hpp"

void PhoneBook::contentIn(std::string stdString, std::string *input)
{
	while (true) {
		input->clear();
		std::cout << stdString;
		std::getline(std::cin, *input);
		if (std::cin.eof() || std::cin.fail()) 
		{
			std::cout << "The end";
			exit(0);
		}
		if (!input->empty())
			break ;
		std::cout << "!! Try again" << std::endl;
	}
}

void	PhoneBook::commandAdd()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (_saveIdx == 8)
    {
		_saveIdx = 0;
        _full = true;
    }
	PhoneBook::contentIn("First_Name : ", &firstName);
	_contact[_saveIdx].setFirstName(firstName);
		PhoneBook::contentIn("Last_Name : ", &lastName);
	_contact[_saveIdx].setLastName(lastName);
		PhoneBook::contentIn("Nick_Name : ", &nickName);
	_contact[_saveIdx].setNickName(nickName);
		PhoneBook::contentIn("Phone_Number : ", &phoneNumber);
	_contact[_saveIdx].setPhoneNumber(phoneNumber);
		PhoneBook::contentIn("Darkest_Secret : ", &darkestSecret);
	_contact[_saveIdx].setDarkestSecret(darkestSecret);
	_saveIdx++;
	_idx++;
}

void	PhoneBook::printOne(int i)
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "First_Name : " << _contact[i].getFirstName() << std::endl;
    std::cout << "Last_Name : " << _contact[i].getLastName() << std::endl;
    std::cout << "Nick_Name : " << _contact[i].getNickName() << std::endl;
    std::cout << "Phone_Number : " << _contact[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest_Secret : " << _contact[i].getDarkestSecret() << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}

void	PhoneBook::printAll()
{
	std::string firstName;
	std::string	lastName;
	std::string	nickName;

	std::cout << "------------------------------------------" << std::endl;
	for (int i = 0; i < _idx; i++)
	{
		if (i == 8)
			break ;
		firstName = this->_contact[i].getFirstName();
		lastName = this->_contact[i].getLastName();
		nickName = this->_contact[i].getNickName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		if (nickName.length() > 10)
			nickName = nickName.substr(0, 9) + ".";
		std::cout << "| " << i + 1 << " | ";
		std::cout.width(10);
		std::cout << firstName << " | ";
		std::cout.width(10);
		std::cout << lastName << " | ";
		std::cout.width(10);
		std::cout << nickName << " | " << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
}



void	PhoneBook::commandExit()
{
	std::cout << "exit";
	exit(0);
}

void	PhoneBook::commandSearch()
{
	std::string	input;

	if (_idx == 0) {
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	PhoneBook::printAll();
	std::cout << "What do you want of number : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "The end";
		exit(0);
	}
//    (std::cin.fail() || !_full && input > _idx + 1) || (_full && input > 8)
	else if ( input.length() == 1 &&
            ((!_full && input[0] >= '1' && input[0] <= _idx + '0') ||
            (_full && input[0] >= '1' && input[0] <= '8')))
        PhoneBook::printOne(input[0] - '1');
	else
        std::cout << "Invalid input" << std::endl;
}

PhoneBook::PhoneBook():_idx(0),_saveIdx(0),_full(false) {}