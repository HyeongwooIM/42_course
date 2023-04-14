# include "Contact.hpp"

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}
void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}
void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}
void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
std::string	Contact::getFirstName()
{
	return _firstName;
}
std::string	Contact::getLastName()
{
	return _lastName;
}
std::string	Contact::getNickName()
{
	return _nickName;
}
std::string	Contact::getPhoneNumber()
{
	return _phoneNumber;
}
std::string	Contact::getDarkestSecret()
{
	return _darkestSecret;
}