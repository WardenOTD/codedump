/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:38:21 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/23 11:19:45 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_argue(t_data *data, char **av)
{
	int	tmp;

	data->num_of_philo = ft_atoi(av[1]);
	if (data->num_of_philo == -1)
		return (-1);
	tmp = ft_atoi(av[2]);
	if (tmp == -1)
		return (-1);
	data->time_die = (unsigned long)tmp;
	tmp = ft_atoi(av[3]);
	if (tmp == -1)
		return (-1);
	data->time_eat = (unsigned long)tmp;
	tmp = ft_atoi(av[4]);
	if (tmp == -1)
		return (-1);
	data->time_sleep = (unsigned long)tmp;
	return (0);
}

int	create_fork(t_data *data)
{
	data->fid = 0;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->num_of_philo);
	data->tod_end = pthread_mutex_init(&data->lock, 0);
	if (!data->fork)
		return (0);
	while (data->fid < data->num_of_philo)
	{
		pthread_mutex_init(&data->fork[data->fid], 0);
		data->fid++;
	}
	data->fidmax = --data->fid;
	return (1);
}

int	last_n_cur_eat(t_data *data)
{
	data->cur_eat_count = (int *)malloc(sizeof(int) * data->num_of_philo);
	data->time_last_eat = (unsigned long *)malloc(sizeof(unsigned long)
			* data->num_of_philo);
	if (!data->time_last_eat)
		return (0);
	if (!data->cur_eat_count)
		return (0);
	return (1);
}

int	create_thread(t_data *data)
{
	data->id = 0;
	data->philo = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!data->philo)
		return (0);
	while (data->id < data->num_of_philo)
	{
		pthread_create(&data->philo[data->id], 0,
			(void *)thread_func, (void *)data);
		time_start(data);
		usleep(100);
		data->id++;
	}
	data->idmax = --data->id;
	data->death = 0;
	return (1);
}
