/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:33:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 16:49:13 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_lower(int i, va_list list, t_list *count)
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
	ft_putstr_fd(hexed, 1);
	return (++i);
}

int	print_hex_upper(int i, va_list list, t_list *count)
{
	char		*hex;
	unsigned long	j;
	unsigned long	q;
	char		*hexed;
	int			l;

	hex = "0123456789ABCDEF";
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
	ft_putstr_fd(hexed, 1);
	return (++i);
}

void	hex_helper(char **hexed, unsigned long j, unsigned long q, int l, char *hex)
{
	*hexed[l--] = 0;
	while (l >= 0)
	{
		q = j % 16;
		j /= 16;
		*hexed[l--] = hex[q];
	}
}
