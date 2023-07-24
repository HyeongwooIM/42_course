#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &other) const {
	std::cout << _type << " has been " << other.getEffects() << "!" << std::endl;
}