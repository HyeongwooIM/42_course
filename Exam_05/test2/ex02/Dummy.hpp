#pragma once

#include <iostream>
#include "ATarget.hpp"

using std::cout;
using std::string;
using std::endl;


class Dummy:public ATarget {
	private:

	public:
		Dummy():ATarget("Target Practice Dummy"){}
		virtual ~Dummy(){};
		Dummy *clone()const {return new Dummy();}

};