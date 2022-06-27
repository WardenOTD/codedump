#include <stdio.h>

int	main()
{
	int	multiple = 3;
	int	range = 20;
	for (int i = 1; i <= range; i++)
	{
		if (i % multiple == 0)
			printf("%d, ", i);
		else
			continue ;
	}
}
