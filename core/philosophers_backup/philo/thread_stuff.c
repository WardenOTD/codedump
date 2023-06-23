/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:21:53 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/23 14:46:26 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_data *data, int id, t_fock *fock)
{
	unsigned long	time;
	unsigned long	timeeat;

	pthread_mutex_lock(&data->lock_thread);
	time = time_end(data);
	timeeat = data->time_eat;
	data->time_last_eat[id] = time;
	data->cur_eat_count[id]++;
	pthread_mutex_unlock(&data->lock_thread);
	// if (data->death)
	// 	return (0);
	printf("%lu %d is eating\n", time, id + 1);
	usleep(timeeat * 1000);
	pthread_mutex_unlock(&data->fork[fock->l_id]);
	pthread_mutex_unlock(&data->fork[fock->r_id]);
	// if (data->death)
	// 	return (0);
	return (1);
}

int	sleeep(t_data *data, int id)
{
	// if (data->death)
	// 	return (0);
	printf("%lu %d is sleeping\n", time_end(data), id + 1);
	usleep(data->time_sleep * 1000);
	return (1);
}

int	fouck(t_data *data, int id, t_fock *fock)
{
	pthread_mutex_lock(&data->fork[fock->l_id]);
	// if (data->death)
	// 	return (0);
	printf("%lu %d has taken a fork\n", time_end(data), id + 1);
	pthread_mutex_lock(&data->fork[fock->r_id]);
	// if (data->death)
	// 	return (0);
	printf("%lu %d has taken a fork\n", time_end(data), id + 1);
	return (1);
}

void	thread_func2(t_data *data, t_fock *fock, int id)
{
	int	wait;
	int	eatc;
	int	no_eat;
	int	EAT;

	wait = 0;
	while (!wait)
	{
		pthread_mutex_lock(&data->lock_thread);
		wait = data->death;
		eatc = data->cur_eat_count[id];
		no_eat = data->num_of_eat;
		EAT = data->need_eat;
		pthread_mutex_unlock(&data->lock_thread);
		if (eatc == no_eat && EAT == 1)
		{
			while (!eat_check(data))
			{
			}
			break ;
		}
		printf("%lu %d is thinking\n", time_end(data), id + 1);
		if (!fouck(data, id, fock) || wait)
			break ;
		if (!eat(data, id, fock) || wait)
			break ;
		if (!sleeep(data, id) || wait)
			break ;
	}
	pthread_mutex_lock(&data->lock_thread);
	data->death = 1;
	pthread_mutex_unlock(&data->lock_thread);
}

void	thread_func(void *stuff)
{
	t_data	*data;
	t_fock	fock;
	int		id;
	int 	pause;

	pause = 1;
	data = (t_data *)stuff;
	pthread_mutex_lock(&data->lock_thread);
	id = data->id;
	data->cur_eat_count[id] = 0;
	data->time_last_eat[id] = 0;
	if (id == 0)
		fock.l_id = data->fidmax;
	else
		fock.l_id = id - 1;
	fock.r_id = id;
	pthread_mutex_unlock(&data->lock_thread);
	while (pause)
	{
		pthread_mutex_lock(&data->lock_thread);
		pause = data->death;
		pthread_mutex_unlock(&data->lock_thread);
	}
	pthread_mutex_lock(&data->lock_thread);
	if (id % 2 == 0)
		usleep((data->time_die * 1000) / 2);
	pthread_mutex_unlock(&data->lock_thread);
	thread_func2(data, &fock, id);
	pthread_mutex_unlock(&data->fork[fock.l_id]);
	pthread_mutex_unlock(&data->fork[fock.r_id]);
}
