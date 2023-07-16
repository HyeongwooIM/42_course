#include "ShrubberyCreationForm.hpp"

/* orthodox canonical form */
ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137)
	, _target("default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 145, 137)
	, _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
	AForm(src)
	, _target(src._target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}


const std::string	&ShrubberyCreationForm::getTarget() const {
	return _target;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs.is_open())
		std::cout << _target << " cannot open file" << std::endl;
	else { 
		ofs << "		            .        +          .      .          ." << std::endl;
		ofs << "     .            _        .                    ." << std::endl;
		ofs << "  ,              /;-._,-.____        ,-----.__" << std::endl;
		ofs << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
		ofs << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
		ofs << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
		ofs << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
		ofs << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
		ofs << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
		ofs << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
		ofs << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
		ofs << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
		ofs << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
		ofs << "                    \\::.  :\\/:'  /              +" << std::endl;
		ofs << "   .                 `.:.  /:'  }      ." << std::endl;
		ofs << "           .           ):_(:;   \\           ." << std::endl;
		ofs << "                      /:. _/ ,  |" << std::endl;
		ofs << "                   . (|::.     ,`                  ." << std::endl;
		ofs << "     .                |::.    {\\" << std::endl;
		ofs << "                      |::.\\  \\ `." << std::endl;
		ofs << "                      |:::(\\    |" << std::endl;
		ofs << "              O       |:::/{ }  |                  (o" << std::endl;
		ofs << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
		ofs << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
		ofs << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
		ofs.close();
		ofs.close();
		std::cout << _target << "create shrubberry file" << std::endl;
	}
}