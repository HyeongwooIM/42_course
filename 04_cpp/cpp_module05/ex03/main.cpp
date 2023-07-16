#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void testMakingForm() {
	Intern	intern;
	AForm 	*form;

	form = intern.makeForm("robotomy request", "jabae");
	delete form;
	form = intern.makeForm("shrubbery creation", "jabae");
	delete form;
	form = intern.makeForm("presidential pardon", "jabae");
	delete form;
	form = intern.makeForm("unknown form", "jabae");
	delete form;
}

void testValidBureaucrat() {
	Bureaucrat	highest("highest", 1);
	Intern		intern;
	AForm		*form;

	form = intern.makeForm("robotomy request", "jabae");
	highest.signForm(*form);
	highest.executeForm(*form);
	delete form;

	form = intern.makeForm("shrubbery creation", "jabae");
	highest.signForm(*form);
	highest.executeForm(*form);
	delete form;

	form = intern.makeForm("presidential pardon", "jabae");
	highest.signForm(*form);
	highest.executeForm(*form);
	delete form;
}

void testInvalidBureaucrat() {
	Bureaucrat	lowest("lowest", 150);
	Intern		intern;
	AForm		*form;

	form = intern.makeForm("robotomy request", "jabae");
	lowest.signForm(*form);
	lowest.executeForm(*form);
	delete form;

	form = intern.makeForm("shrubbery creation", "jabae");
	lowest.signForm(*form);
	lowest.executeForm(*form);
	delete form;

	form = intern.makeForm("presidential pardon", "jabae");
	lowest.signForm(*form);
	lowest.executeForm(*form);
	delete form;
}

int main() {
	std::cout << "===== test making form =====" << std::endl;
	testMakingForm();

	std::cout << "===== test valid bureaucrat =====" << std::endl;
	testValidBureaucrat();

	std::cout << "===== test invalid bureaucrat =====" << std::endl;
	testInvalidBureaucrat();

	system("leaks bureaucrat");

	return 0;
}