
/*
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}

int	retrieve_digit(char c, int base)
{
	int	max;

	if (base <= 10)
		max = base + '0';
	else
		max = base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max)
		return (c + 10 - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	neg;
	long	out;
	int	digit;

	neg = 1;
	out = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (1)
	{
		digit = retrieve_digit(to_lower(*str), str_base);
		if (digit < 0)
			break;
		out *= str_base;
		out += digit;
		if (out >= __INT_MAX__)
			return (__INT_MAX__ * neg);
		str++;
	}
	return (out * neg);
}

int	main()
{
	int	i = ft_atoi_base("47876ADA", 16);
	printf("%d\n", i);
}
