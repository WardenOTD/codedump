/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:54:37 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/01 16:07:09 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_hex(t_flags *flag, t_specifier *spc, va_list list)
{
	char			*address2;
	unsigned long	address;

	address = va_arg(list, unsigned long);
	address2 = hex_convert(spc, address);
	if (!address2)
		return (0);
	cmp(flag, address2);
	other(spc, flag);
	return (1);
}

char	*hex_convert(t_specifier *spc, unsigned long address)
{
	int				count;
	unsigned long	fake_address;
	char			*cadd;

	count = 0;
	fake_address = address;
	while (address != 0)
	{
		fake_address /= 16;
		count++;
	}
	cadd = (char *)ft_calloc(count + 1, sizeof(char));
	if (!cadd)
		return (0);
	if (spc->x == 1 || spc->p == 1)
		hexx(&cadd, address, count);
	if (spc->upperx == 1)
		uhexx(&cadd, address, count);
	return (cadd);
}

void	hexx(char **cadd, unsigned long address, int count)
{
	const char		*hex;
	unsigned long	tmp;

	hex = "0123456789abcdef";
	while (count > 0)
	{
		tmp = address % 16;
		address /= 16;
		*cadd[count] = hex[tmp];
		count--;
	}
}

void	uhexx(char **cadd, unsigned long address, int count)
{
	const char		*uhex;
	unsigned long	tmp;

	uhex = "0123456789ABCDEF";
	while (count > 0)
	{
		tmp = address % 16;
		address /= 16;
		*cadd[count] = uhex[tmp];
		count--;
	}
}
