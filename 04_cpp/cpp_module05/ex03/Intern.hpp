#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();
		Intern & operator=(Intern const &rhs);

		AForm *findForm(std::string const &formName, std::string const &target);
		AForm *makeForm(std::string const &formName, std::string const &target);

		class FormNotFoundException : public std::exception {
			const char *what() const throw();
		};
};

#endif