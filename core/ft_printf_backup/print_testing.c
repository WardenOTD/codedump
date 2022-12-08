#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

char	*buffered_0(char *str)
{
	int		i = 0;
	char	*tmp;
	int	j;
	while (str[i] == '0')
		i++;
	j = i;
	while (str[j])
		j++;
	tmp = (char *)malloc(sizeof(char) * (j-i+1));
	tmp[j-i] = 0;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	free(str);
	printf("\n%s\n", tmp);
	return (tmp);
}

int	main()
{
	ft_printf("\n\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n\n");

	// unsigned int	lll;

	// works
	// printf("\nTest1\n");
	// printf("system:_asdadasdasd\n");
	// ft_printf("mine:_asdadasdasd\n");

	// works
	// char	c = 'f';
	// printf("\nTest2\n");
	// printf("system:_%-5c\n", c);
	// ft_printf("mine:_%-5c\n", c);

	// works
	// printf("\nTest3\n");
	// printf("system:_%-10s\n", "string");
	// ft_printf("mine:_%-10s\n", "string");

	//	works
	// printf("\ntest4\n");
	// printf("system:_%-14p\n", &lll);
	// ft_printf("mine:_%-14p\n", &lll);

	//	works
	// printf("\ntest5\n");
	// printf("system:_%+-5d\n", 6);
	// ft_printf("mine:_%+-5d\n", 6);

	//	works
	// printf("\ntest5.5\n");
	// printf("system:_%+5d\n", 6);
	// ft_printf("mine:_%+5d\n", 6);

	// 	works
	// printf("\ntest6\n");
	// printf("system:_%+-i\n", 6);
	// ft_printf("mine:_%+-i\n", 6);

	//	works
	// lll = 1234567;
	// printf("\ntest7\n");
	// printf("system:_%-10u\n", lll);
	// ft_printf("mine:_%-10u\n", lll);

	//	works ---doesn't append 0x
	printf("\ntest8\n");
	printf("system:_%-#60x\n", 23458);
	ft_printf("mine:_%-#60x\n", 23458);

	//	works ---doesn't append 0x
	printf("\ntest9\n");
	printf("system:_%-#60X\n", 439819);
	ft_printf("mine:_%-#60X\n", 439819);

	//	works? after percent printed no newline
	// printf("\ntest9\n");
	// printf("system:_%%\n");
	// ft_printf("mine:_%%\n");


	// printf("\n\n\n");
	// system("leaks a.out");
}
