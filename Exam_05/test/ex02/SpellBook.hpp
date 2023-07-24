#pragma once

#include <iostream>
#include <map>

#include "ASpell.hpp"


class SpellBook {
	private:
		typedef std::map<std::string, ASpell *>::iterator map_it;
		std::map<std::string, ASpell *> spells;
		SpellBook(const SpellBook &other);
		SpellBook&operator=(const SpellBook & other);
	public:
		SpellBook(){}
		virtual ~SpellBook() {
			for (map_it it = spells.begin(); it != spells.end(); ++it)
				delete it->second;
		}
		void learnSpell(ASpell *aspell) {
			spells[aspell->getName()] = aspell->clone();
		}
		void forgetSpell(const std::string &spell) {
			delete spells.find(spell)->second;
			spells.erase(spell);
		}
		ASpell *createSpell(const std::string &spell) {
			if (spells.find(spell) != spells.end())
				return spells[spell];
			return NULL;
		}
};