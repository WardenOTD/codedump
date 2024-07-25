#include "ASpell.hpp"

ASpell::ASpell(string name, string effects) : sName(name), sEffects(effects){

}

ASpell & ASpell::operator=(ASpell const &a)
{
	sName = a.getName();
	sEffects = a.getEffects();
	return *this;
}

ASpell::ASpell(ASpell const & a)
{
	*this = a;
}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const{
	return (sName);
}

std::string ASpell::getEffects() const{
	return (sEffects);
}

void ASpell::launch(ATarget const & target) const{
	target.getHitBySpell(*this);
}

