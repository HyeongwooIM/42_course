#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &rhs);

		const std::string	&getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);

		class GradeTooHighException: public std::exception {
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif