#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string namee)
{
	name = namee;
}

Zombie::~Zombie()
{
	std::cout << "kys " << name << std::endl;
}
