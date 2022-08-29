/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:25 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/29 15:48:00 by jteoh            ###   ########.fr       */
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
		ft_lstadd_back(&count, &str[i]);
		i++;
	}
	return (ft_lstsize(count));
}
