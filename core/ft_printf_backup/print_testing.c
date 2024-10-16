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
	// int	p;

	// // works
	// printf("\nTest1\n");
	// p = printf("system:_asdadasdasd\n");
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_asdadasdasd\n");

	// // works
	// char	c = 'f';
	// printf("\nTest2\n");
	// p=printf("system:_%c\n", c);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%c\n", c);

	// // works
	// printf("\nTest3\n");
	// p=printf("system:_%s\n", "string");
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%s\n", "string");

	// //	works
	// printf("\ntest4\n");
	// p=printf("system:_%p\n", &lll);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%p\n", &lll);

	// //	works
	// printf("\ntest5\n");
	// p=printf("system:_%d\n", 6);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%d\n", 6);

	// // 	works
	// printf("\ntest6\n");
	// p=printf("system:_%i\n", 6);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%i\n", 6);

	// //	works
	// lll = 1234567;
	// printf("\ntest7\n");
	// p=printf("system:_%u\n", lll);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%u\n", lll);

	// //	works
	// printf("\ntest8\n");
	// p=printf("system:_%x\n", 23458);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%x\n", 23458);

	// //	works
	// printf("\ntest9\n");
	// p=printf("system:_%X\n", 439819);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%X\n", 439819);

	// //	works
	// printf("\ntest10\n");
	// p = printf("system:_%%\n");
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%%\n");

	printf(" %x ", LONG_MIN);
	printf("\n\n\n");
	ft_printf(" %x ", LONG_MIN);
	ft_printf("\n\n\n");

	printf("\n\n\n");
	// system("leaks a.out");
}
