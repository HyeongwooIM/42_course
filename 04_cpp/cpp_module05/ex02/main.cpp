#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "RobotomyRequestForm" << std::endl;
	std::cout << "===== case 1 : valid & random 50% test =====" << std::endl;
	{
		RobotomyRequestForm	robotomyRequestForm;
		Bureaucrat	bureaucrat("bureaucrat", 40);
		
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
	}
	std::cout << "===== case 2 : invalid =====" << std::endl;
	{
		RobotomyRequestForm	robotomyRequestForm;
		Bureaucrat	bureaucrat("bureaucrat", 55);
		
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
	}
	std::cout << "===== case 3 : invalid =====" << std::endl;
	{
		RobotomyRequestForm	robotomyRequestForm;
		Bureaucrat	bureaucrat("bureaucrat", 130);
		
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
	}
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "===== case 1 : valid =====" << std::endl;
	{
		PresidentialPardonForm	presidentialPardonForm;
		Bureaucrat	bureaucrat("bureaucrat", 3);
		
		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);
	}
	std::cout << "===== case 2 : invalid =====" << std::endl;
	{
		PresidentialPardonForm	presidentialPardonForm;
		Bureaucrat	bureaucrat("bureaucrat", 24);
		
		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);
	}
	std::cout << "===== case 3 : invalid =====" << std::endl;
	{
		PresidentialPardonForm	presidentialPardonForm;
		Bureaucrat	bureaucrat("bureaucrat", 130);
		
		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);
	}
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "===== case 1 : valid =====" << std::endl;
	{
		ShrubberyCreationForm	shrubberyCreationForm;
		Bureaucrat	bureaucrat("bureaucrat", 130);
		
		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.executeForm(shrubberyCreationForm);
	}
	std::cout << "===== case 2 : invalid =====" << std::endl;
	{
		ShrubberyCreationForm	shrubberyCreationForm;
		Bureaucrat	bureaucrat("bureaucrat", 140);
		
		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.executeForm(shrubberyCreationForm);
	}
	std::cout << "===== case 3 : invalid =====" << std::endl;
	{
		ShrubberyCreationForm	shrubberyCreationForm;
		Bureaucrat	bureaucrat("bureaucrat", 150);
		
		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.executeForm(shrubberyCreationForm);
	}
	return 0;
}
