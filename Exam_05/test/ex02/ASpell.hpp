#pragma once

#include "ATarget.hpp"
#include <iostream>

class ATarget;

class ASpell {
	private:
		std::string _name;
		std::string _effects;

	public:
		ASpell(){};
		ASpell(std::string name, std::string effects): _name(name), _effects(effects){};
		virtual ~ASpell(){};
		std::string getName() const {return _name;};
		const std::string getEffects() const {return _effects;};
		virtual ASpell *clone() const = 0;
		void launch(ATarget const &other);

};