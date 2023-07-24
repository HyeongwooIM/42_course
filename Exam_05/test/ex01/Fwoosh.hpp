#pragma once

#include <iostream>

#include "ASpell.hpp"

class Fwoosh: public ASpell{
	private:
		
	public:
		Fwoosh(): ASpell("Fwoosh", "fwooshed") {}
		virtual ~Fwoosh(){}
		Fwoosh *clone() const {return new Fwoosh();}
};