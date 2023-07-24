#pragma once

#include <iostream>
#include "ATarget.hpp"

class Dummy: public ATarget{
	private:

	public:
		Dummy(): ATarget("Target Practice Dummy"){}
		virtual ~Dummy(){}
		Dummy *clone() const {return new Dummy();};
};