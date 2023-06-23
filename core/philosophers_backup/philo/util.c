/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:01:36 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/23 17:00:49 by jteoh            ###   ########.fr       */
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
	pthread_mutex_lock(&data->time_lock);
	data->tod_start = ((start.tv_sec * 1000) + (start.tv_usec / 1000));
	pthread_mutex_unlock(&data->time_lock);
}

unsigned long	time_end(t_data *data)
{
	struct timeval	end;
	unsigned long	ret;
	unsigned long	start;

	gettimeofday(&end, 0);
	pthread_mutex_lock(&data->time_lock);
	start = data->tod_start;
	pthread_mutex_unlock(&data->time_lock);
	ret = ((end.tv_sec * 1000) + (end.tv_usec / 1000))
		- start;
	return (ret);
}

int	eat_check(t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!data->need_eat)
		return (0);
	while (i < data->num_of_philo)
	{
		pthread_mutex_lock(&data->get_last_eaten[i]);
		if (data->cur_eat_count[i] >= data->num_of_eat)
			flag++;
		pthread_mutex_unlock(&data->get_last_eaten[i]);
		i++;
	}
	if (flag == data->num_of_philo)
		return (1);
	return (0);
}
