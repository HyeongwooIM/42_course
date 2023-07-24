#pragma once

#include <iostream>
#include "ATarget.hpp"

using std::cout;
using std::string;
using std::endl;


class BrickWall:public ATarget {
	private:

	public:
		BrickWall():ATarget("Inconspicuous Red-brick Wall"){}
		virtual ~BrickWall(){};
		BrickWall *clone()const {return new BrickWall();}

};