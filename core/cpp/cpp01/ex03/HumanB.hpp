#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB {
	public:
		void	attack();
		void	setWeapon(Weapon &wep);
		HumanB(std::string nem);
	private:
		Weapon	*weapon;
		std::string name;
};

#endif
