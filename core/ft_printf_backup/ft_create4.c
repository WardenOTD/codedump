/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:22:46 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/13 15:35:21 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_pointer(t_flags *flag, va_list list)
{
	char			*address2;
	unsigned long	address;

	address = va_arg(list, unsigned long);
	address2 = hex_convertp(address);
	if (!address2)
		return (0);
	append_0x(address2);
	write_to_fd(address2, flag, 1);
	free(address2);
	return (1);
}

char	*hex_convertp(unsigned long address)
{
	int				count;
	unsigned long	fake_address;
	char			*cadd;

	count = 1;
	fake_address = address;
	while (fake_address >= 16)
	{
		fake_address /= 16;
		count++;
	}
	count += 2;
	cadd = (char *)ft_calloc((count + 1), sizeof(char));
	if (!cadd)
		return (0);
	phexx(cadd, address, count);
	return (cadd);
}

void	phexx(char *cadd, unsigned long address, int count)
{
	const char		*hex;
	unsigned long	tmp;

	hex = "0123456789abcdef";
	count--;
	while (count != -1)
	{
		tmp = address % 16;
		address /= 16;
		cadd[count] = hex[tmp];
		count--;
	}
}

void	append_0x(char *str)
{
	str[0] = '0';
	str[1] = 'x';
}
