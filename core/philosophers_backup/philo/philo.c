/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:44:46 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/21 17:53:11 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_all(t_data *data)
{
	data->id = 0;
	data->idmax = 0;
	data->fid = 0;
	data->fidmax = 0;
	data->tod_start = 0;
	data->num_of_philo = 0;
	data->num_of_eat = 0;
	data->need_eat = 0;
	data->time_die = 0;
	data->time_eat = 0;
	data->time_sleep = 0;
	data->death = 1;
}

int	the_free(t_data *data, int i)
{
	free(data->fork);
	free(data->get_last_eaten);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->time_lock);
	pthread_mutex_destroy(&data->lock_thread);
	if (i == 1)
		write(1, "Fork Malloc Error\n", 18);
	else if (i == 2)
	{
		free(data->philo);
		write(1, "Philo Malloc Error\n", 19);
	}
	else if (i == 3)
	{
		free(data->philo);
		free(data->time_last_eat);
		free(data->cur_eat_count);
	}
	else if (i == 4)
	{
		free(data->time_last_eat);
		free(data->cur_eat_count);
		write(1, "Malloc Error\n", 13);
	}
	return (0);
}

void	main3(t_data *data, int i, unsigned long ded, int idm)
{
	while ((ded < data->time_die))
	{
		if (i == idm)
		{
			if (eat_check(data))
			{
				toggle_death(data);
				break ;
			}
			usleep((data->time_die * 1000) / 2);
			i = -1;
		}
		i++;
		pthread_mutex_lock(&data->get_last_eaten[i]);
		ded = time_end(data) - data->time_last_eat[i];
		pthread_mutex_unlock(&data->get_last_eaten[i]);
	}
}

void	main2(t_data *data, int i, int j)
{
	unsigned long	ded;
	int				idm;

	pthread_mutex_lock(&data->lock_thread);
	ded = time_end(data) - data->time_last_eat[i];
	idm = data->idmax;
	pthread_mutex_unlock(&data->lock_thread);
	main3(data, i, ded, idm);
	toggle_death(data);
	you_die(data, i);
	while (j < data->num_of_philo)
		pthread_join(data->philo[j++], 0);
	j = 0;
	while (j < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->fork[j]);
		pthread_mutex_destroy(&data->get_last_eaten[j++]);
	}
	the_free(data, 3);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_all(&data);
	if (get_argue(&data, argv) == -1)
		return (write(1, "Error\n", 6));
	if (!create_fork(&data))
		return (the_free(&data, 1));
	if (!last_n_cur_eat(&data))
		return (the_free(&data, 4));
	if (argc == 5)
	{
		if (!create_thread(&data))
			return (the_free(&data, 2));
	}
	else if (argc == 6)
	{
		data.need_eat = 1;
		data.num_of_eat = ft_atoi(argv[5]);
		if (data.num_of_eat < 0)
			return (write(1, "Error\n", 6));
		if (!create_thread(&data))
			return (the_free(&data, 2));
	}
	main2(&data, 0, 0);
	return (0);
}
