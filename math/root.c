/*
	Only works for perfect roots.
	Honestly no idea how I can make it work for non perfect roots.
	Tried incrementing by 0.000000001 but computor was too bad to handle it so I gave up on that idea.
	Maybe it might've worked but who knows.
	I added :
	||	if (j + j > base)	||
	||		return (0);		||
	at line 22 just to make sure it doesn't continue on infinitely since it can't work on non perfect roots.
	And yes, trying to make a code for root is kind of retarded but I mean, no harm in trying ¯\_(ツ)_/¯.
*/

#include <stdio.h>

float	power_recur(float base, int pow);

float	ft_root(float base, int root)
{
	float	j = 0;
	while (power_recur(j, root) != base)
	{
		if (j + j > base)
			return (0);
		j++;
	}
	return (j);
}

float	power_recur(float base, int pow)
{
	if (pow <= 0)
		return (1);
	else if (pow > 0)
	{
		return (base * power_recur(base, --pow));
	}
}

int	main()
{
	int	root = 3;
	float	base = 27;
	printf("%f\n", ft_root(base, root));
	return (0);
}
