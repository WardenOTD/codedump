int	ft_is_prime(int nb);
#include <stdio.h>
int	main()
{
	for (int i = -10; i <= 10000; i++)
	{
		if (ft_is_prime(i) == 1)
			printf("%d\n",i);
	}
}
