#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*pos;
	pos = new Zombie[N];
	while (N >= 0)
	{
		pos[N].SET(name);
		N--;
	}
	return (pos);
}
