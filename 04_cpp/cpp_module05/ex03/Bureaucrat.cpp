#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat():
	_name("default")
	, _grade(150) {

}

Bureaucrat::Bureaucrat(const std::string name, int grade):
	_name(name)
	, _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):
	_name(src._name)
	, _grade(src._grade) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}


const std::string	&Bureaucrat::getName() const {
	return _name;
}

int					Bureaucrat::getGrade() const {
	return _grade;
}


void	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	else
		--_grade;
}

void	Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		++_grade;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executesd " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
	return out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
}