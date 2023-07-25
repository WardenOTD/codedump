#include "Weapon.hpp"

std::string	&Weapon::getType()
{
	std::string	&wepref = type;
	return (wepref);
}

void		Weapon::setType(std::string param)
{
	std::string	&typeref = getType();
	typeref.assign(param);
}

Weapon::Weapon(std::string str)
{
	type.assign(str);
}

Weapon::Weapon()
{
}
