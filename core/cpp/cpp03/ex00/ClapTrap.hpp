#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	public:
		// Orthodox Canonical Class Form
		ClapTrap();
		ClapTrap(const ClapTrap &ct);
		ClapTrap & operator= (const ClapTrap &ct);
		~ClapTrap();

		//others
		ClapTrap(std::string name);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string	name;
		int				HP;
		unsigned int	EP;
		int				AD;
};

#endif
