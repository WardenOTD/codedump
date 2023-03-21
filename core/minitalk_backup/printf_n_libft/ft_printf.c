/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:25 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/13 12:11:18 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_flags		flag;
	t_specifier	spc;
	va_list		list;

	flag.printed = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			default_specifier(&spc);
			out(&spc, &flag, list, str);
			str += 2;
			continue ;
		}
		str += percent(str);
		ft_putchar_fd(*str, 1);
		flag.printed += 1;
		str++;
	}
	va_end(list);
	return (flag.printed);
}

int	percent(const char *str)
{
	if (*str == '%' && *(str + 1) == '%')
		return (1);
	return (0);
}

void	default_specifier(t_specifier *spc)
{
	spc->c = 0;
	spc->s = 0;
	spc->p = 0;
	spc->di = 0;
	spc->u = 0;
	spc->x = 0;
	spc->upperx = 0;
	spc->hash = 0;
}
