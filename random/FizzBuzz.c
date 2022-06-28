#include <stdio.h>

int	ft_fizzbuzz(int start, int end, int fizz, int buzz)
{
	if (start > end)
		return (0);
	else
	{
		for (int i = start; i <= end; i++)
		{
			if (i % fizz == 0 && i % buzz == 0)
				printf("FizzBuzz");
			else if (i % fizz == 0)
				printf("Fizz");
			else if (i % buzz == 0)
				printf("Buzz");
			else
				printf("%d", i);
			printf("\n");
		}
		return (0);
	}
}

int	main()
{
	ft_fizzbuzz(0, 100, 3, 5);
	return (0);
}
