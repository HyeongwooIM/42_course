#pragma once

#include <iostream>
#include "ASpell.hpp"

using std::cout;
using std::string;
using std::endl;

class Fwoosh:public ASpell {
	private:

	public:
		Fwoosh():ASpell("Fwoosh", "fwooshed"){}
		virtual ~Fwoosh(){};
		Fwoosh *clone()const {return new Fwoosh();}

};