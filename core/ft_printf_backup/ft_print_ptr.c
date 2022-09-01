/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:40:54 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/01 11:05:27 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_ptr(va_list list)
{
	char	*address;

	address = address_hex(list);
	if (!address)
		return (0);
	address = buffered_0(address);
	if (!address)
		return (0);
	address = add0x(address);
	if (!address)
		return (0);
	return (address);
}

char	*clear_buffered_0(char *str)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	while (str[i] == '0')
		i++;
	j = i;
	while (str[j])
		j++;
	tmp = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!tmp)
		return (0);
	tmp[j - i] = 0;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	free(str);
	return (tmp);
}

char	*address_hex(va_list list)
{
	char			*hex;
	unsigned long	j;
	unsigned long	q;
	char			*hexed;
	int				l;

	hex = "0123456789abcdef";
	j = va_arg(list, unsigned long);
	q = j;
	l = 0;
	while (q > 0)
	{
		q /= 10;
		l++;
	}
	hexed = (char *)malloc(sizeof(char) * (l + 1));
	if (!hexed)
		return (0);
	hex_helper(&hexed, j, q, l, hex);
	return (hexed);
}

char	*add0x(char *address)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(address) + 2;
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (0);
	tmp[j] = 0;
	tmp[i++] = '0';
	tmp[i++] = 'x';
	j = 0;
	while (address[j])
		tmp[i++] = address[j++];
	free(address);
	return (tmp);
}
