int	ft_iterative_factorial(int nb);
#include <stdio.h>
int	main()
{
	for (int i = -2; i <= 20; i++)
		printf("factorial of %d is %d\n",i , ft_iterative_factorial(i));
	return 0;
}
