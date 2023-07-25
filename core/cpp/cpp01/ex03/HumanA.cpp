#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string nem, Weapon &wep) : weapon(wep)
{
	name.assign(nem);
}
