#pragma once

#include <iostream>
#include "ATarget.hpp"
#include <map>

using std::cout;
using std::string;
using std::endl;
using std::map;

class TargetGenerator {
	private:
		typedef map<string, ATarget *>::iterator map_it;
		std::map<string, ATarget *> Targets;
		TargetGenerator(const TargetGenerator &other);
		TargetGenerator &operator=(const TargetGenerator &other);

	public:
		TargetGenerator(){
		}
		virtual ~TargetGenerator() {
			for (map_it it = Targets.begin(); it != Targets.end(); ++it)
				delete it->second;
		}
		void learnTargetType(ATarget *Target) {
			Targets[Target->getType()] = Target->clone();
		}
		void forgetTargetType(string const& Target) {
			delete Targets.find(Target)->second;
			Targets.erase(Target);
		}
		ATarget *createTarget(string const &Target) {
			if (Targets.find(Target) != Targets.end())
				return Targets[Target];
			return NULL;
		}
};