/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:49:35 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/13 12:17:38 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_char(t_flags *flag, va_list list)
{
	char	c;

	c = va_arg(list, int);
	ft_putchar_fd(c, 1);
	flag->printed += 1;
	return (1);
}

int	if_int(t_specifier *spc, t_flags *flag, va_list list)
{
	int				di;
	unsigned int	u;
	char			*c;

	if (spc->di == 1)
	{
		di = va_arg(list, int);
		c = ft_itoa(di);
	}
	if (spc->u == 1)
	{
		u = va_arg(list, unsigned int);
		c = utoa(u);
	}
	write_to_fd(c, flag, 1);
	free(c);
	return (1);
}

unsigned int	digitcount(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (count + 1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*utoa(unsigned int n)
{
	unsigned int	count;
	char			*arr;
	unsigned int	temp;

	count = digitcount(n);
	arr = (char *)malloc(count * sizeof(char) + 1);
	if (!arr)
		return (0);
	arr[count--] = '\0';
	while (count > 0)
	{
		temp = n % 10;
		n /= 10;
		arr[count] = temp + '0';
		count--;
	}
	temp = n % 10;
	arr[count] = temp + '0';
	return (arr);
}
