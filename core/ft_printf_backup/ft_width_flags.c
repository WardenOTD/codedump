/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:02:34 by jteoh             #+#    #+#             */
/*   Updated: 2022/11/29 10:52:02 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg(t_flags *flag)
{
	int	i;

	i = 0;
	while (flag->extract[i] != 0)
	{
		if (flag->extract[i] == '-')
		{
			flag->neg = 1;
			break ;
		}
		i++;
	}
}

void	pos(t_flags *flag)
{
	int	i;

	i = 0;
	while (flag->extract[i] != 0)
	{
		if (flag->extract[i] == '+')
		{
			flag->pos = 1;
			break ;
		}
		i++;
	}
}

int	minimum(t_flags *flag)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (flag->extract[i] != 0)
	{
		if (flag->extract[i] >= '0' && flag->extract[i] <= '9')
			min = min * 10 + (flag->extract[i] - '0');
		i++;
	}
	return (min);
}
