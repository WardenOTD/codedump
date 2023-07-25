#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	if (argc == 8)
	{
		Zombie	*die, *die2;

		die = newZombie(argv[1]);
		die->announce();
		delete die;
		randomChump(argv[2]);
		die2 = newZombie(argv[3]);
		die2->announce();
		delete die2;
		randomChump(argv[4]);
		randomChump(argv[5]);
		randomChump(argv[6]);
		randomChump(argv[7]);
	}
	else
		std::cout << "please give me 7 names" << std::endl;
}
