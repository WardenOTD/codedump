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
	// p=printf("system:_%-5c\n", c);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%-5c\n", c);

	// // works
	// printf("\nTest3\n");
	// p=printf("system:_%-10s\n", "string");
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%-10s\n", "string");

	// //	works
	// printf("\ntest4\n");
	// p=printf("system:_%-14p\n", &lll);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%-14p\n", &lll);

	// //	works
	// printf("\ntest5\n");
	// p=printf("system:_%+-5d\n", 6);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%+-5d\n", 6);

	// //	works
	// printf("\ntest5.5\n");
	// p=printf("system:_%+5d\n", 6);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%+5d\n", 6);

	// // 	works
	// printf("\ntest6\n");
	// p=printf("system:_%+-i\n", 6);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%+-i\n", 6);

	// //	works
	// lll = 1234567;
	// printf("\ntest7\n");
	// p=printf("system:_%-10u\n", lll);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%-10u\n", lll);

	// //	works
	// printf("\ntest8\n");
	// p=printf("system:_%#60x\n", 23458);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%#60x\n", 23458);

	// printf("\ntest8.5\n");
	// p=printf("system:_%-#60x\n", 23458);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%-#60x\n", 23458);

	// //	works
	// printf("\ntest9\n");
	// p=printf("system:_%#60X\n", 439819);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%#60X\n", 439819);

	// printf("\ntest9.5\n");
	// p=printf("system:_%-#60X\n", 439819);
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%-#60X\n", 439819);

	// //	works
	// printf("\ntest9\n");
	// p = printf("system:_%%\n");
	// printf("\n----system printed: %d----\n", p);
	// ft_printf("mine:_%%\n");

	ft_printf("wait for it... %#Xp", 42);
	ft_printf("\n");
	int	p = ft_printf("%c", 'a');
	ft_printf("\n%d\n", p);
	int	l = ft_printf("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
	ft_printf("\n%d\n", l);
	int	k = ft_printf("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
	ft_printf("\n%d\n", k);
	int	j = printf("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
	printf("\n%d\n", j);

	printf("\n\n\n");
	// system("leaks a.out");
}
