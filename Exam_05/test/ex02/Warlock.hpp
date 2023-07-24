#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
	private:
		std::string _name;
		std::string _title;
		Warlock(){};
		Warlock(Warlock const &other): _name(other._name), _title(other._title) {}
		Warlock &operator=(const Warlock& rhs) {
			_title = rhs._title;
			_name = rhs._name;
			return *this;
		}
		SpellBook spells;

	public:
		Warlock(std::string name, std::string title): _name(name), _title(title){std::cout << _name << ": This looks like another boring day." << std::endl;}
		virtual ~Warlock(){
			std::cout << _name << ": My job here is done!" << std::endl;
		};
		const std::string getName() const {return _name;};
		const std::string getTitle() const {return _title;};
		void setTitle(const std::string &title) {_title = title;};
		void introduce() const {
			std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl; 
		};
		void learnSpell(ASpell *aspell) {
			spells.learnSpell(aspell);
		}
		void forgetSpell(std::string spell) {
			spells.forgetSpell(spell);
		}
		void launchSpell(std::string spell, ATarget &target) {
			ASpell *tmp = spells.createSpell(spell);
			if (tmp)
				tmp->launch(target);
		}
};
