#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		
	public:
		AForm();
		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &src);
		virtual ~AForm();
		AForm &operator=(const AForm &rhs);

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException: public std::exception {
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			const char *what() const throw();
		};
		class FormNotSignedException: public std::exception {
			// virtual const char *what() const throw();
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
