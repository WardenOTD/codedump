/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:25 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 17:22:32 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	t_list	*count;
	int	i;

	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '%')
		{
			//calls function...?
			//returns i??
			//i += returned i????
			//continue ;??????
		}
		ft_putchar_fd(str[i], 1);
		ft_lstadd_back(&count, ft_lstnew("+1"));
		i++;
	}
	return (ft_lstsize(count));
}

int	minimum_width(const char *str, int i, va_list list, t_list *count)
{
	int	zero;
	int	width;

	zero = 0;
	width = 0;
	if (str[++i] == '0')
	{
		zero = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		width = ft_atoi(&str[i]);
		i++;
	}
	if (str[i] == '.')
	{
		//does something with another function ????
	}
	if ( 0)
		return (0);
	return (i);
}

int	rolecall(const char *str, int i, va_list list, t_list *count)
{
	if (str[i] == 'c')
		return (print_char(i, list, count));
	if (str[i] == 's')
		return (print_str(i, list, count));
	if (str[i] == 'p')
		return (print_ptr(i, list, count));
	if (str[i] == 'd' || str[i] == 'i')
		return (print_deci_int(i, list, count));
	if (str[i] == 'u')
		return (print_unsigned(i, list, count));
	if (str[i] == 'x')
		return (print_hex_lower(i, list, count));
	if (str[i] == 'X')
		return (print_hex_upper(i, list, count));
	return (0);
}
