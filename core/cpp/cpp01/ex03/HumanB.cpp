#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wep)
{
	weapon = &wep;
}

HumanB::HumanB(std::string nem)
{
	name.assign(nem);
}
