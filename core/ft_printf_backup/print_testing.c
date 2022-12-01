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
	char	*hex = "0123456789abcdef";
	int	i = 100;
	unsigned long	c = (unsigned long)&i;
	unsigned long	cringe = c;
	unsigned long	tmp;
	int	q = 0;
	char	*address;
	printf("\nc: %ld\ncringe: %ld\n\n", c, cringe);
	while (cringe > 0)
	{
		cringe /= 16;
		q++;
	}
	address = (char *)malloc(sizeof(char) * (q + 1));
	if (!address)
		return (0);
	address[q--] = 0;
	cringe = c;
	while (q > 0)
	{
		tmp = cringe % 16;
		cringe /= 16;
		address[q] = hex[tmp];
		printf("%d  ---  %c\n", q, address[q]);
		q--;
	}
	tmp = cringe % 16;
	address[q] = hex[tmp];
	printf("address before buffer: %s\n", address);
	printf("address before buffer: 0x%s\n", address);
	address = buffered_0(address);
	printf("address after buffer: %s\n", address);
	printf("address after buffer: 0x%s\n", address);

	printf("\n");
	printf("lx &i: 0x%0lx\n", (unsigned long)&i);
	printf("p: %p\n", &i);
	printf("lx c: 0x%0lx\n", c);
	printf("address: 0x%s\n\n\n", address);
	printf("===============================================================\n\n");
	int	yes = printf("%9.5i\n", 42);
	printf("previous print returned: %d\n\n\n", yes);
	int	integer = -100;
	unsigned int	unint = 200;
	unsigned int	result = (unsigned int)(integer - unint);
	long	lol = 10;
	int		lolol = 10;
	printf("long = %li ,, int = %i\n\n", lol, lolol);
	printf("%u\n\n", result);
	printf("%u\n\n", -15);
	lolol = -15;
	printf("%lu\n\n", lol);
	printf("%u\n\n", UINT_MAX);
	printf("\n\n\n\n");

	printf("#lx &i: %0#lx\n", (unsigned long)&i);
	printf("0xlx &i: 0x%0lx\n", (unsigned long)&i);
	printf("%#5x\n", 100);
	printf("%5x\n", 100);
	printf("%#5X\n", 100);
	printf("%5X\n", 100);
	printf("% 5d\n", 100);
	printf("% 5d\n", -100);
	printf("%05d\n", 100);
	printf("%+5d\n", 100);
	printf("%-5d\n", 100);
	printf("%.5d\n", 100);
	printf("bro %.10s man\n", "holy shittaa");
	printf("%-2d\n", 100);
	printf("%+5d\n", 100);
	printf("%#x\n", 100);
	printf("%10.5s\n", "123456");
	printf("%d,%010% 12\n", 100);
	printf("%020f\n", 10.10);
	printf("%020.3f\n", 10.10);
	printf("%20d\n", 9);
	printf("%.20d\n", 9);
	printf("%020d\n", 9);
	printf("%5s\n", "0123456");
	printf("%.5s\n", "0123456");
	printf("%1s\n", "0123456");
	printf("%.1s\n", "0123456");
	printf("%.06d\n", 1000);
	printf("%06d\n", 1000);
	printf("%.010f\n", 0.5);
	printf("%010f\n", 0.5);
	printf("%.2d\n", 1000);
	printf("%02d\n", 1000);
	printf("%-5d\n", -500);
	printf("%+5d\n", -500);


	unsigned int	lll = 560;
	unsigned long	ppp = (unsigned long)&lll;
	printf("%#50lX\n", ppp);
	printf("%-50p\n", &lll);
	printf("%-+5d\n", lll);

	unsigned int	un = 500;
	printf("%-5u\n", un);
	printf("%-6s\n", "suck");
	printf("%-6c\n", 'f');
	printf("%-c\n", 'f');

	ft_printf("\n\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n\n");

	printf("asdadasdasd\n");
	ft_printf("asdadasdasd\n");

	// printf("%c\n", 'f');
	// ft_printf("%c\n", 'f');

	printf("%s\n", "string");
	ft_printf("%s\n", "string");

	// printf("%p\n", &lll);
	// ft_printf("%p\n", &lll);

	// printf("%d\n", 6);
	// ft_printf("%d\n", 6);

	// printf("%i\n", 6);
	// ft_printf("%i\n", 6);

	// printf("%u\n", lll);
	// ft_printf("%u\n", lll);

	// printf("%x\n", 100);
	// ft_printf("%x\n", 100);

	// printf("%X\n", 100);
	// ft_printf("%X\n", 100);

	printf("%%\n");
	ft_printf("%%\n");

	printf("\n\n\n\n");
	// system("leaks a.out");
}
