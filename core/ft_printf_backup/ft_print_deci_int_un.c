/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:45:12 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 10:49:13 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_deci_int(const char *str, int i, va_list list, t_list *count)
{
	int	num;
	int	length;
	int	printed;

	num = va_arg(list, int);
	printed = num;
	while (printed > 0)
	{
		printed /= 10;
		length++;
	}
	while (printed++ < length)
		ft_lstadd_back(&count, ft_lstnew("+1"));
	ft_putnbr_fd(num, 1);
	return (++i);
}
