#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

		const std::string	&getTarget() const;

		void 				execute(Bureaucrat const &executor) const;
};

#endif