/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:40:54 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 16:52:37 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(int i, va_list list, t_list *count)
{
	char	*address;
	int		j;

	j = 0;
	address = address_hex(list, count);
	if (!address)
		return (0);
	address = buffered_0(address);
	if (!address)
		return (0);
	while (j++ < 2)
		ft_lstadd_back(&count, ft_lstnew("+1"));
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(address, 1);
	return (++i);
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

int	address_hex(va_list list, t_list *count)
{
	char		*hex;
	unsigned long	j;
	unsigned long	q;
	char		*hexed;
	int			l;

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
	l = ft_strlen(hexed);
	j = 0;
	while (j++ < l)
		ft_lstadd_back(&count, ft_lstnew("+1"));
	return (hexed);
}

