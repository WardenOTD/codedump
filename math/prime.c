#include <stdio.h>

void	prime(int base, int max)
{
	int	i;
	while (base >= 0 && base <= max)
	{
		for (i = 2; (i <= base); i++)
		{
			if (base <= 1)
				break ;
			if (i == base)
			{
				printf("%d, ", base);
				break ;
			}
			else if (base % i == 0)
				break ;
		}
		base++;
	}
}

int	main()
{
	prime(0, 100);
	return (0);
}
