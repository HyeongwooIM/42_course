#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
	int		_idx;
	int		_saveIdx;
	bool	_full;
	Contact	_contact[8];
	void	printAll();
	void	printOne(int i);
	void 	contentIn(std::string stdString, std::string *input);

	public:
	PhoneBook();
	void	commandSearch();
	void	commandAdd();
	void	commandExit();
};

#endif