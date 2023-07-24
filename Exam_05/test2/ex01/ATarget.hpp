#pragma once

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class ATarget {
	private:
		std::string _type;
	public:
		ATarget() {}
		ATarget(const ATarget &src) {*this = src;}
		ATarget &operator=(const ATarget &rhs){
			_type = rhs._type;
			return *this;
		}
		ATarget(std::string type):_type(type){};
		virtual ~ATarget(){};
		std::string getType() {return _type;};
		virtual ATarget *clone() const = 0;
		void getHitBySpell(ASpell const &other) const;
};