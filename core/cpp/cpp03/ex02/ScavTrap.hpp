#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Orthodox Canonical Class Form
		ScavTrap();
		ScavTrap(const ScavTrap &st);
		ScavTrap & operator= (const ScavTrap &st);
		~ScavTrap();

		// Others
		ScavTrap(std::string name);
		void	attack(const std::string &target);
		void	guardGate();
	private:

};

#endif
