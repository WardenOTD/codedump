/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:08:08 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/24 18:10:53 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modify_atoi(const char *str, t_stack *stack)
{
	long	out;
	int		sign;

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
	detect_alph(str, stack);
	return (modify_atoi_half(str, stack, out, sign));
}

int	modify_atoi_half(const char *str, t_stack *stack, long out, int sign)
{
	while (*str >= '0' && *str <= '9')
	{
		if (out >= 214748364 && *str > '7' && sign == 1)
		{
			ft_putstr_fd("overflow\n", 2);
			full_free(stack);
			exit (1);
		}
		if (out >= 214748364 && *str > '8' && sign == -1)
		{
			ft_putstr_fd("negative overflow\n", 2);
			full_free(stack);
			exit (1);
		}
		out = out * 10 + (*str - '0');
		str++;
	}
	return ((int)(out * sign));
}
