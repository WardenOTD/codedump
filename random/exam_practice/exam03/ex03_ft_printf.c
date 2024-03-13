#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#include <stdio.h>

int	string(va_list list)
{
	char	*str = va_arg(list, char *);
	int	printed = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != 0)
	{
		write(1, str, 1);
		printed++;
		str++;
	}
	return (printed);
}

int	dec(va_list list)
{
	int				num = va_arg(list, int);
	unsigned int	unum;
	unsigned int	tmp;
	char			*out;
	int				i = 0;
	int				printed = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		printed++;
		unum = num * -1;
	}
	else
		unum = num;
	if (unum == 0)
	{
		write(1, "0", 1);
		return (printed += 1);
	}
	tmp = unum;
	while (tmp != 0)
	{
		tmp /= 10;
		i++;
	}
	printed += i;
	out = malloc(sizeof(char) * (i+1));
	if (!out)
		return (-1);
	out[i--] = 0;
	tmp = unum;
	while (unum != 0)
	{
		tmp = unum % 10;
		out[i--] = tmp + '0';
		unum /= 10;
	}
	i = 0;
	while (out[i] != 0)
	{
		write(1, &out[i], 1);
		i++;
	}
	free(out);
	return (printed);
}

int	hex(va_list list)
{
	unsigned int	num = va_arg(list, unsigned int);
	unsigned int	tmp;
	char			*out;
	char			*hex = "0123456789abcdef";
	int				i = 0;
	int				printed = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (printed += 1);
	}
	tmp = num;
	while (tmp != 0)
	{
		tmp /= 16;
		i++;
	}
	printed += i;
	out = malloc(sizeof(char) * (i+1));
	if (!out)
		return (-1);
	out[i--] = 0;
	tmp = num;
	while (num != 0)
	{
		tmp = num % 16;
		out[i--] = hex[tmp];
		num /= 16;
	}
	i = 0;
	while (out[i] != 0)
	{
		write(1, &out[i], 1);
		i++;
	}
	free(out);
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list list;
	va_start(list, str);
	int	printed = 0;
	int	error = 0;

	while (*str != 0)
	{
		if (*str == '%')
		{
			if (*(str+1) == 's')
			{
				printed += string(list);
				str+=2;
			}
			else if (*(str+1) == 'd')
			{
				error = dec(list);
				if (error == -1)
					return (-1);
				printed += error;
				str+=2;
			}
			else if (*(str+1) == 'x')
			{
				error = hex(list);
				if (error == -1)
					return (-1);
				printed += error;
				str+=2;
			}
			else
			{
				write(1, str, 1);
				printed++;
				str++;
			}
		}
		if (*str != '%' && *str != 0)
		{
			write(1, str, 1);
			printed++;
			str++;
		}
	}
	va_end(list);
	return (printed);
}


int	main()
{
	int val;
	val = INT_MIN;
	while (val < INT_MAX)
	{
		printf ("%d\n", ft_printf("Hexadecimal for %d is %x and %s\n", val, val, NULL));
		printf ("%d\n", printf("Hexadecimal for %d is %x and %s\n", val, val, NULL));
		write(1,"\n",1);
		val++;
	}
}
