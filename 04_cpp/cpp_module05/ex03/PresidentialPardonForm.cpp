#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm("PresidentialPardonForm", 25, 5)
	, _target("default") {

	}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5)
	, _target(target) {

	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
	AForm(src)
	, _target(src._target) {

	}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}


const std::string &PresidentialPardonForm::getTarget() const {
	return _target;
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}