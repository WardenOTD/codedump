/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:15:29 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/18 11:36:59 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	out;
	int	sign;

	sign = 1;
	out = 0;
	while (*str == '\t' || *str == '\f' || *str == '\r'
		|| *str == '\v' || *str == ' ' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (out >= 2147483647 && sign == 1)
			return (2147483647);
		if (out >= 2147483647 && sign == -1)
			return (-2147483648);
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out * sign);
}
