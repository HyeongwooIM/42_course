#pragma once

#include <iostream>
#include <map>

#include "ATarget.hpp"

class TargetGenerator {
	private:
		typedef std::map<std::string, ATarget *>::iterator map_it;
		TargetGenerator(const TargetGenerator &other);
		TargetGenerator &operator=(const TargetGenerator &other);
		std::map<std::string, ATarget *> spells;

	public:
		TargetGenerator(){}
		virtual ~TargetGenerator(){
			for(map_it it = spells.begin(); it !=spells.end(); ++it)
				delete it->second;
		}
		void learnTargetType(ATarget *aspell) {
			spells[aspell->getType()] = aspell->clone();
		}
		void forgetTargetType(const std::string &spell) {
			delete spells.find(spell)->second;
			spells.erase(spell);
		}
		ATarget *createTarget(const std::string &spell) {
			if (spells.find(spell) != spells.end())
				return spells[spell];
			return NULL;
		}
};
