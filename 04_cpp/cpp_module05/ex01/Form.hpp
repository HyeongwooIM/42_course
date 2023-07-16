#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; // 순환참조를 막기 위해 선언만 해놓고 정의는 나중에 한다.

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		
	public:
		Form();
		Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &src);
		~Form();
		Form &operator=(const Form &rhs);

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception {
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
