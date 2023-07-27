#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Orthodox Canonical Class Form
		FragTrap();
		FragTrap(const FragTrap &st);
		FragTrap & operator= (const FragTrap &st);
		~FragTrap();

		// Others
		FragTrap(std::string name);
		void	highFivesGuys();
	private:

};

#endif
