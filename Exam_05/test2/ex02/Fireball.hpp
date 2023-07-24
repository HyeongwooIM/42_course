#pragma once

#include <iostream>
#include "ASpell.hpp"

using std::cout;
using std::string;
using std::endl;

class Fireball:public ASpell {
	private:

	public:
		Fireball():ASpell("Fireball", "burnt to a crisp"){}
		virtual ~Fireball(){};
		Fireball *clone()const {return new Fireball();}
};