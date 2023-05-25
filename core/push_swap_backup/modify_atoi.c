/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:08:08 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 11:19:30 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modify_atoi(const char *str, t_stack *stack)
{
	long	out;
	int		sign;

	sign = 1;
	out = 0;
	only_negative(str, stack);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	detect_alph(str, stack);
	return (modify_atoi_half(str, stack, out, sign));
}

int	modify_atoi_half(const char *str, t_stack *stack, long out, int sign)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		detect_alph(str, stack);
		is_negative(str[i], stack);
		if (out >= 214748364 && str[i] > '7' && sign == 1)
			dead(stack);
		if (out >= 214748364 && str[i] > '8' && sign == -1)
			dead(stack);
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(out * sign));
}
