/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:21:53 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/23 16:44:01 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_data *data, t_philo ref, t_fock fock)
{
	unsigned long	time;

	time = time_end(data);
	pthread_mutex_lock(&data->get_last_eaten[ref.id]);
	data->time_last_eat[ref.id] = time;
	++data->cur_eat_count[ref.id];
	pthread_mutex_unlock(&data->get_last_eaten[ref.id]);
	print_time_stamp(data, "%lu %d is eating\n", time, ref.id + 1);
	usleep(ref.time_eat * 1000);
	pthread_mutex_unlock(&data->fork[fock.l_id]);
	pthread_mutex_unlock(&data->fork[fock.r_id]);
	return (1);
}

int	sleeep(t_data *data, t_philo ref)
{
	print_time_stamp(data, "%lu %d is sleeping\n", time_end(data), ref.id + 1);
	usleep(ref.time_sleep * 1000);
	return (1);
}

int	fouck(t_data *data, t_philo ref, t_fock fock)
{
	pthread_mutex_lock(&data->fork[fock.l_id]);
	print_time_stamp(data, "%lu %d has taken a fork\n",
		time_end(data), ref.id + 1);
	pthread_mutex_lock(&data->lock_thread);
	if (data->num_of_philo == 1)
		return (0);
	pthread_mutex_unlock(&data->lock_thread);
	pthread_mutex_lock(&data->fork[fock.r_id]);
	print_time_stamp(data, "%lu %d has taken a fork\n",
		time_end(data), ref.id + 1);
	return (1);
}

void	thread_func2(t_data *data, t_philo ref, t_fock fock)
{
	int	wait;

	wait = 0;
	while (!wait)
	{
		if (!fouck(data, ref, fock))
			break ;
		eat(data, ref, fock);
		sleeep(data, ref);
		print_time_stamp(data, "%lu %d is thinking\n",
			time_end(data), ref.id + 1);
		pthread_mutex_lock(&data->death_lock);
		wait = data->death;
		pthread_mutex_unlock(&data->death_lock);
	}
}

void	thread_func(void *stuff)
{
	t_philo	ref;
	t_data	*data;
	t_fock	fock;
	int		pause;

	data = (t_data *)stuff;
	init_thread_stuff(data, &ref, &fock);
	pause = 1;
	while (pause)
	{
		pthread_mutex_lock(&data->death_lock);
		pause = data->death;
		pthread_mutex_unlock(&data->death_lock);
	}
	if (ref.id % 2 == 1)
	{
		print_time_stamp(data, "%lu %d is thinking\n",
			time_end(data), ref.id + 1);
		usleep((ref.time_die * 1000) / 3);
	}
	thread_func2(data, ref, fock);
}
