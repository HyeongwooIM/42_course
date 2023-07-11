#include "Brain.hpp"
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		if (i < 50)
			_ideas[i] = "idea1";
		else
			_ideas[i] = "idea2";
	}
}
Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy construcotr called" << std::endl;
	*this = src;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain copy assignment called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return _ideas[i];
	return "";
}
void Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		_ideas[i] = idea;
}