#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << GET() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SET(std::string namee)
{
	name = namee;
}

std::string	Zombie::GET()
{
	return (name);
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "kys " << name << std::endl;
}
