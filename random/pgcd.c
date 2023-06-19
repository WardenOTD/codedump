/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	s1;
	int	s2;
	int i;

	if (argc == 3)
	{
		s1 = atoi(argv[1]);
		s2 = atoi(argv[2]);
		if (s1 <= 0 || s2 <= 0)
		{
			printf("\n");
			return (0);
		}
		if (s1 > s2)
			i = s2;
		if (s2 > s1)
			i = s1;
		while (i >= 0)
		{
			if (s1 % i == 0 && s2 % i == 0)
			{
				printf("%d", i);
				break ;
			}
			i--;
		}
	}
	printf("\n");
	return (0);
}
