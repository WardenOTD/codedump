/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:21:53 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/22 15:23:58 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_data *data, int id, t_fock *fock)
{
	time_end(data);

	// printf("philo id = %d, time_last_eat = %ld, time_die = %ld\n", id + 1, data->tod_end - data->time_last_eat[id], data->time_die);
	// if (data->time_eat > data->time_die)
	// {
	// 	usleep(data->time_die * 1000);
	// 	time_end(data);
	// 	printf("%lu %d has died\n", data->tod_end, id + 1);
	// 	pthread_mutex_unlock(&data->fork[fock->l_id]);
	// 	pthread_mutex_unlock(&data->fork[fock->r_id]);
	// 	data->death = 1;
	// 	return (0);
	// }
	// if (data->time_last_eat[id] == 0)
	// 	data->time_last_eat[id] = data->tod_end;
	// else
	// 	data->time_last_eat[id] = data->tod_end - data->time_last_eat[id];
	data->time_last_eat[id] = data->tod_end;
	if (data->death)
		return (0);
	printf("%lu %d is eating\n", data->tod_end, id + 1);
	usleep(data->time_eat * 1000);
	pthread_mutex_unlock(&data->fork[fock->l_id]);
	pthread_mutex_unlock(&data->fork[fock->r_id]);
	data->cur_eat_count[id]++;
	if (data->death)
		return (0);
	return (1);
}

int	sleeep(t_data *data, int id)
{
	time_end(data);
	if (data->death)
		return (0);
	printf("%lu %d is sleeping\n", data->tod_end, id + 1);
	// if (data->time_sleep > data->time_die)
	// {
	// 	usleep(data->time_die * 1000);
	// 	time_end(data);
	// 	printf("%lu %d has died\n", data->tod_end, id + 1);
	// 	// printf("nerd died in his sleep\n");
	// 	data->death = 1;
	// 	return (0);
	// }
	usleep(data->time_sleep * 1000);
	return (1);
}

int	fouck(t_data *data, int id, t_fock *fock)
{
	pthread_mutex_lock(&data->fork[fock->l_id]);
	time_end(data);

	// printf("philo id = %d, time_last_eat = %ld, time_die = %ld\n", id + 1, data->tod_end - data->time_last_eat[id], data->time_die);
	// if ((data->tod_end - data->time_last_eat[id]) > data->time_die)
	// if (data->time_last_eat[id] > data->time_die)
	// {
		// printf("died grabbing one fork\n");
		// pthread_mutex_unlock(&data->fork[fock->l_id]);
		// data->death = 1;
		// return (0);
	// }

	if (data->death)
		return (0);

	printf("%lu %d has taken a fork\n", data->tod_end, id + 1);

	pthread_mutex_lock(&data->fork[fock->r_id]);
	time_end(data);

	// printf("philo id = %d, time_last_eat = %ld, time_die = %ld\n", id + 1, data->tod_end - data->time_last_eat[id], data->time_die);
	// if ((data->tod_end - data->time_last_eat[id]) > data->time_die)
	// if (data->time_last_eat[id] > data->time_die)
	// {
		// printf("%lu %d has died\n", data->tod_end, id + 1);
		// printf("died grabbing 2 forks\n");
		// pthread_mutex_unlock(&data->fork[fock->l_id]);
		// pthread_mutex_unlock(&data->fork[fock->r_id]);
		// data->death = 1;
		// return (0);
	// }

	if (data->death)
		return (0);

	printf("%lu %d has taken a fork\n", data->tod_end, id + 1);

	return (1);
}

void	thread_func(void *stuff)
{
	t_data	*data;
	t_fock	fock;
	int		id;

	data = (t_data *) stuff;
	id = data->id;

	data->cur_eat_count[id] = 0;
	data->time_last_eat[id] = 0;

	if (id == 0)
		fock.l_id = data->fidmax;
	else
		fock.l_id = id - 1;
	fock.r_id = id;

	while (data->death)
	{
	}
	if (id % 2 == 0)
		usleep((data->time_die * 1000) / 2);
	// printf("left %d, right %d, id %d\n", fock.l_id, fock.r_id, id + 1);
	while (!data->death)
	{
		if (data->cur_eat_count[id] == data->num_of_eat && data->need_eat == 1)
		{
			while (!eat_check(data))
			{
			}
			break ;
		}

		time_end(data);
		// if (data->tod_end - data->time_last_eat[id] > data->time_die || data->death)
		// // if (data->time_last_eat[id] > data->time_die || data->death)
		// {
		// 	printf("%lu %d has died\n", data->tod_end, id + 1);
		// 	data->death = 1;
		// 	break ;
		// }

		printf("%lu %d is thinking\n", data->tod_end, id + 1);
		if (!fouck(data, id, &fock) || data->death)
			break ;
		if (!eat(data, id, &fock) || data->death)
			break ;
		if (!sleeep(data, id) || data->death)
			break ;
	}
	pthread_mutex_unlock(&data->fork[fock.l_id]);
	pthread_mutex_unlock(&data->fork[fock.r_id]);

	data->death = 1;
}
