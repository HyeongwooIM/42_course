#pragma once

#include <iostream>
#include "ATarget.hpp"
#include <map>

using std::cout;
using std::string;
using std::endl;
using std::map;

class SpellBook {
	private:
		typedef map<string, ASpell *>::iterator map_it;
		std::map<string, ASpell *> spells;
		SpellBook(const SpellBook &other);
		SpellBook &operator=(const SpellBook &other);

	public:
		SpellBook(){
		}
		virtual ~SpellBook() {
			for (map_it it = spells.begin(); it != spells.end(); ++it)
				delete it->second;
		}
		void learnSpell(ASpell *spell) {
			spells[spell->getName()] = spell->clone();
		}
		void forgetSpell(string const& spell) {
			delete spells.find(spell)->second;
			spells.erase(spell);
		}
		ASpell *createSpell(string const &spell) {
			if (spells.find(spell) != spells.end())
				return spells[spell];
			return NULL;
		}
};