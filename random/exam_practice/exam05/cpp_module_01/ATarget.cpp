#include "ATarget.hpp"

ATarget::ATarget(std::string type) : tType(type)
{

}

ATarget & ATarget::operator=(ATarget const & a)
{
	tType = a.getType();
	return *this;
}

ATarget::ATarget(ATarget const & a)
{
	*this = a;
}

ATarget::~ATarget()
{

}

std::string ATarget::getType() const
{
	return (tType);
}

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << tType << " has been " << spell.getEffects() << "!" << std::endl;
}
