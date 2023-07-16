#include "Intern.hpp"


Intern::Intern() { 

}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() { 

}

Intern &Intern::operator=(const Intern &rhs) {
	return *this;
}


AForm *Intern::findForm(std::string const &formName, std::string const &target) {
	const std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int					idx;

	for (idx = 0; idx < 4; idx++) {
		if (!formName.compare(formNames[idx])) {
			break;
		}
	}
	switch (idx) {
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw FormNotFoundException();
	}
	return NULL;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	AForm *form;
	try {
		form = findForm(formName, target);
		std::cout << "Intern creates " << form->getName() << std::endl;
		return form;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return NULL;
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}