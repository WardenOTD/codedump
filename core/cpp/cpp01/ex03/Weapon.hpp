#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
	public:
		std::string	&getType();
		void		setType(std::string param);
		Weapon(std::string str);
		Weapon();
	private:
		std::string	type;
};

#endif
