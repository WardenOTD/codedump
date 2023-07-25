#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	public:
		void	announce();
		Zombie(std::string namee);
		~Zombie();
	private:
		std::string	name;
};



Zombie	*newZombie(std::string name);

void	randomChump(std::string name);

#endif
