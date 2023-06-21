/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:01:36 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/21 18:06:59 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	out;

	out = 0;
	while (*str == '\t' || *str == '\f' || *str == '\r'
		|| *str == '\v' || *str == ' ' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
	}
	while (*str >= '0' && *str <= '9')
	{
		if (out >= __INT_MAX__)
			return (-1);
		out = out * 10 + (*str - '0');
		str++;
	}
	if (ft_isdigit(*str) == 0 && *str != 0)
		return (-1);
	return ((int)out);
}

void	time_start(t_data *data)
{
	struct timeval	start;

	gettimeofday(&start, 0);
	data->tod_start = ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}

void	time_end(t_data *data)
{
	struct timeval	end;

	gettimeofday(&end, 0);
	data->tod_end = ((end.tv_sec * 1000) + (end.tv_usec / 1000)) - data->tod_start;
}
