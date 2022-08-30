/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:29:50 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 10:38:24 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(const char *str, int i, va_list list, t_list *count)
{
	char	c;

	c = va_arg(list, char);
	ft_putchar_fd(c, 1);
	ft_lstadd_back(&count, ft_lstnew("+1"));
	return (++i);
}

int	print_str(const char *str, int i, va_list list, t_list *count)
{
	char	*strr;
	int		length;
	int		printed;

	printed = 0;
	*strr = va_arg(list, char *);
	length = ft_strlen(strr);
	ft_putstr_fd(strr, 1);
	while (printed < length)
	{
		ft_lstadd_back(&count, ft_lstnew("+1"));
		printed++;
	}
	return (++i);
}
