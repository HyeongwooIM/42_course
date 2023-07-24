#pragma once

#include <iostream>
#include "ATarget.hpp"

using std::cout;
using std::string;
using std::endl;
class ATarget;

class ASpell{
	private:
		string _name;
		string _effects;

	public:
		ASpell(){};
		ASpell(string name, string effects): _name(name), _effects(effects){}
		const string getName() const {return _name;};
		const string getEffects() const {return _effects;};
		virtual ASpell* clone() const = 0;
		virtual ~ASpell(){}
		void launch(const ATarget& target);
};