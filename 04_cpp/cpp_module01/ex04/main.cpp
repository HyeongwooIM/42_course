#include <iostream>
#include <fstream>


int main(int ac, char **av)
{
	std::string 	filename;
	std::string		s1;
	std::string		s2;
	std::string		buff;

	if (ac != 4)
	{
		std::cout << "[error] Plese check num of argument" << std::endl;
		return 1;
	}
	std::ifstream	fileSrc(av[1]);
	std::ofstream	fileDst(std::string(std::string(av[1]) + ".replace"));
	if(!fileSrc.is_open())
	{
		std::cout << "[Error] File open fail : ifstream" << std::endl;
		return 1;
	}
	if(!fileDst.is_open())
	{
		fileSrc.close();
		std::cout << "[Error] File open fail : ofstream" << std::endl;
		return 1;
	}
	s1 = av[2];
	s2 = av[3];
	if (s1.empty())
	{
		std::cout << "[Error] s1 is empty" << std::endl;
		fileSrc.close();
		fileDst.close();
		return 1;
	}
	while (std::getline(fileSrc, buff, '\0'))
	{
		if (fileSrc.fail())
		{
			std::cout << "[Error] can't read file" << std::endl;
			fileSrc.close();
			fileDst.close();
			return 1;
		}
		if (std::cin.eof())
			break ;
		size_t pos = 0;
		while ((pos = buff.find(s1, pos)) != std::string::npos)
		{
			buff.erase(pos, s1.length());
			buff.insert(pos, s2);
			pos += s2.length();
		}
		fileDst << buff;
	}
	fileDst.close();
}