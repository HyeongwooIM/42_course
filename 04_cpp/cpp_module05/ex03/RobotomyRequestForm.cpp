#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45)
	, _target("default") {
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
	AForm("RobotomyRequestForm", 72, 45)
	, _target(target) {
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	AForm(src)
	, _target(src._target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}


const std::string	&RobotomyRequestForm::getTarget() const {
	return _target;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		if (!rand() % 2)
			std::cout << _target << " robotomization failed" << std::endl;
		else {
			std::cout << "Drilling noises drilllllllllllllll≈≈≈≈≈≈≈≈≈≈≈≈≈!!!" << std::endl;
			std::cout << _target << " has been robotomized successfully" << std::endl;
		}
	}
}