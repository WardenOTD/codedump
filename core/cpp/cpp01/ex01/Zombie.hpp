#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	public:
		void	announce();
		void	SET(std::string namee);
		std::string	GET();
		Zombie();
		~Zombie();
	private:
		std::string	name;
};



Zombie	*zombieHorde(int N, std::string name);

#endif
