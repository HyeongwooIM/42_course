#include "ScalarConverter.hpp"

Convert::Convert():
	_f(0)
	, _d(0)
	, _i(0)
	, _c(0)
	, _isChar(false)
	, _isInt(false)
	, _isFloat(false)
	, _isNan(false)
{

}

Convert::Convert(Convert const &src): 
	_f(src._f)
	, _d(src._d)
	, _i(src._i)
	, _c(src._c)
	, _isChar(src._isChar)
	, _isInt(src._isInt)
	, _isFloat(src._isFloat)
	, _isNan(src._isNan)
{

}

Convert::~Convert()
{

}

Convert & Convert::operator=(Convert const &rhs)
{
	if (this == &rhs)
		return *this;
	_f = rhs._f;
	_d = rhs._d;
	_i = rhs._i;
	_c = rhs._c;
	_isChar = rhs._isChar;
	_isInt = rhs._isInt;
	_isFloat = rhs._isFloat;
	_isNan = rhs._isNan;
	return *this;
}

Convert::Convert(const char *str):
	_f(0)
	, _d(0)
	, _i(0)
	, _c(0)
	, _isChar(false)
	, _isInt(false)
	, _isFloat(false)
{
	char *endptr = NULL;
	if (strlen(str) == 3 && str[0] == '\'' && str[2] == '\'')
	{
		_c = static_cast<char>(*str);
		_i = static_cast<int>(str[1]);
		_f = static_cast<float>(*str);
		_d = static_cast<double>(_i);
		_isChar = true;
		_isFloat = true;
		_isInt = true;
		std::cout << _c << _i << _f << _d << std::endl;
	}
	else {
	_d = strtod(str, &endptr);
	if (*endptr && strcmp(endptr, "f") != 0 )
		_isNan = true;
	_f = static_cast<float>(_d);
	_i = static_cast<int>(_d);
	_c = static_cast<char>(_d);
	if (static_cast<int>(_c) == _i)
		_isChar = true;
	if (static_cast<double>(_i) == floor(_d))
		_isInt = true;
	if (static_cast<double>(_f) == _d)
		_isFloat = true;
	}
}

void	Convert::printChar()
{
	if (_isNan)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (_i >= 32 && _i <= 126)
		std::cout << "char: '" << _c << "'" << std::endl;
	else if (_isChar)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void	Convert::printInt()
{
	if (_isNan)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (_isInt)
		std::cout << "int: " << _i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	Convert::printFloat()
{
	if (_isNan)
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	std::cout << "float: " << std::setprecision(6) << _f;
	if (std::floor(_f) == _f && (_f <= 1000000 && _f >= -1000000))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	Convert::printDouble()
{
	if (_isNan)
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	std::cout << "double: " << std::setprecision(15) << _d;
	if (std::floor(_d) == _d && (_d <= 1000000000000000 && _d >= -1000000000000000))
		std::cout << ".0";
	std::cout << std::endl;
}

void	Convert::printAll()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}
