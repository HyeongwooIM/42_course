#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ATarget;

class ASpell {
private:
	string name;
	string effects;

public:
	ASpell() {}
	ASpell(const ASpell &other) {*this = other;}
	ASpell(string name, string effects): name(name), effects(effects) {}
	virtual ~ASpell() {}
	ASpell &operator=(const ASpell &other) {
		name = other.getName();
		effects = other.getEffect();
		return *this;
	}
	string getName() const {return name;}
	string getEffect() const {return effects;}
	virtual ASpell *clone() const = 0;
	void launch(ATarget const &other);

};

#include "ATarget.hpp"
