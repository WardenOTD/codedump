/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:40:54 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 10:41:31 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(const char *str, int i, va_list list, t_list *count)
{
	char	*address;
	int		j;
	int		l;

	l = 0;
	j = 0;
	address = buffered_0(address);
	ft_putstr_fd("0x", 1);
	l = print_hex_lower(str, i, list, count);
	if (l == 0)
		return (0);
	while (j++ < 2)
		ft_lstadd_back(&count, ft_lstnew("+1"));
	return (l);
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
	tmp[j - i] = 0;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	free(str);
	return (tmp);
}
