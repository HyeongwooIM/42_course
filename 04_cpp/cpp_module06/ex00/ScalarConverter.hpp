#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Convert
{
	private:
		float		_f;
		double		_d;
		int			_i;
		char		_c;
		bool		_isChar;
		bool		_isInt;
		bool		_isFloat;
		bool		_isNan;
		Convert();
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();

	public:
		Convert(const Convert &src);
		~Convert();
		Convert & operator=(const Convert &rhs);
		Convert(const char *str);

		void 	printAll();
};

#endif