#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_fizzbuzzinter(int start, int end, int fizz, int buzz);
int	playerinput(int	i, int fizz, int buzz, char *input, int numinput);
int	main();

int	ft_fizzbuzzinter(int start, int end, int fizz, int buzz)
{
	if (start > end)
		return (0);
	else
	{
		char	*input = malloc(8 * sizeof(char));
		int		numinput = 0;
		for (int i = start; i <= end; i++)
		{
			if (i % 2 == 0)
			{
				if (playerinput(i, fizz, buzz, input, numinput) == 1)
					continue ;
				else if (playerinput(i, fizz, buzz, input, numinput) == 0)
					break ;
			}
			if (i % 2 != 0)
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
		}
	}
	return (0);
}

int	playerinput(int	i, int fizz, int buzz, char *input, int numinput)
{
	if (i % fizz == 0 && i % buzz == 0)
	{
		scanf("%s", input);
		if (strcmp(input, "FizzBuzz") == 0 || strcmp(input, "fizzbuzz") == 0 || strcmp(input, "fizzBuzz") == 0 || strcmp(input, "Fizzbuzz") == 0)
			return (1);
		else
		{
			printf("WRONG\n");
			return (0);
		}
	}
	else if (i % fizz == 0)
	{
		scanf("%s", input);
		if (strcmp(input, "Fizz") == 0 || strcmp(input, "fizz") == 0)
			return (1);
		else
		{
			printf("WRONG\n");
			return (0);
		}
	}
	else if (i % buzz == 0)
	{
		scanf("%s", input);
		if (strcmp(input, "Buzz") == 0 || strcmp(input, "buzz") == 0)
			return (1);
		else
		{
			printf("WRONG\n");
			return (0);
		}
	}
	else
	{
		scanf("%d", &numinput);
		if (numinput == i)
			return (1);
		else
		{
			printf("WRONG\n");
			return (0);
		}
	}
}

int	main()
{
	ft_fizzbuzzinter(1, 15, 3, 5);
	return (0);
}
