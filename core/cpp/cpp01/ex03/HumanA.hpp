#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA {
	public:
		void	attack();
		HumanA(std::string nem, Weapon &wep);
	private:
		Weapon	&weapon;
		std::string name;
};

#endif
