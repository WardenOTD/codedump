/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:25 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/03 14:50:57 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_flags	*flag;
	va_list	list;
	int		p;

	default_flag(flag);
	va_start(list, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			p = flag_set(++str, 0, flag, list);
			if (p == 0)
				return (0);
			str += p;
			// create array  with the format flags and specifiers to print;;
		}
		if (*str == '%' && *(str + 1) == '%')
		{
			ft_putchar_fd(*str, 1);
			str += 2;
		}
		ft_putchar_fd(*str, 1);
		flag->printed += 1;
		str++;
	}
	va_end(list);
	return (flag->printed);
}

void	default_flag(t_flags *flag)
{
	flag->space = 0;
	flag->zero = 0;
	flag->precision = 0;
	flag->neg = 0;
	flag->pos = 0;
	flag->hash = 0;
	flag->printed = 0;
}
