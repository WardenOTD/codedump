#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		Zombie	*die;
		int		i = 0;

		die = zombieHorde(std::stoi(argv[1]), argv[2]);
		while (i < std::stoi(argv[1]))
		{
			die[i].announce();
			i++;
		}
		delete[] die;
	}
	else
		std::cout << "amount and name" << std::endl;
}
