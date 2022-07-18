int	ft_find_next_prime(int nb);
#include <stdio.h>
int	main()
{
	for (int i = 0; i < 1048129; i++)
	{
		printf("%d, %d\n", i, ft_find_next_prime(i));
	}
}
