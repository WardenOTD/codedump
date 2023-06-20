/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:44:46 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/20 17:45:21 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// need to work on death.....!!

void	eat(t_data *data, int id, t_fock *fock)
{
	time_end(data);
	fock->time_last_eat = data->tod_end;
	printf("%ul philosopher %d is eating.\n", data->tod_end, id);
	usleep(data->time_eat);
	pthread_mutex_unlock(data->fork[fock->l_id]);
	pthread_mutex_unlock(data->fork[fock->r_id]);
}

void	sleep(t_data *data, int id)
{
	time_end(data);
	printf("%ul philosopher %d is sleeping.\n", data->tod_end, id);
	usleep(data->time_sleep);
}

int	create_fork(t_data *data)
{
	data->fid = 0;

	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
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

void	fock(t_data *data, int id, t_fock *fock)
{
	pthread_mutex_lock(data->fork[fock->l_id]);
	time_end(data);
	if (fock->time_last_eat > data->time_die)
	{
		time_end(data);
		printf("%ul philosopher %d has died.\n", data->tod_end, id);
		data->death = 1;
	}
	printf("%ul philosopher %d has taken a fork.\n", data->tod_end, id);
	pthread_mutex_lock(data->fork[fock->r_id]);
	time_end(data);
	printf("%ul philosopher %d has taken a fork.\n", data->tod_end, id);
}

void	thread_func(void *stuff)
{
	t_data	*data;
	t_fock	fock;
	int		id;

	fock.time_last_eat = 0;
	time_start(data);
	data = (t_data *) stuff;
	id = data->id;
	if (id % 2 == 0)
		usleep(1000);
	if (id == 0)
		fock.l_id = data->fidmax;
	else
		fock.l_id = id - 1;
	fock.r_id = id + 1;
	while (!data->death)
	{

		time_end(data);
		printf("%ul philosopher %d is thinking.\n", data->tod_end, id);
		fock(data, id, &fock);
		eat(data, id);
		sleep(data, id);
	}
}

int	create_thread(t_data *data)
{
	data->id = 0;

	data->philo = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!data->philo)
		return (0);
	while (data->id < data->num_of_philo)
	{
		pthread_create(&data->philo[data->id], 0, (void *) thread_func, (void *)data);
		usleep(100);
		data->id++;
	}
	data->idmax = --data->id;
	return (1);
}

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

void	init_all(t_data *data)
{
	data->id = 0;
	data->idmax = 0;
	data->fid = 0;
	data->fidmax = 0;
	data->tod_start = 0;
	data->tod_end = 0;
	data->num_of_philo = 0;
	data->num_of_eat = 0;
	data->cur_eat_count = 0;
	data->time_die = 0;
	data->time_eat = 0;
	data->time_sleep = 0;
	data->death = 0;
}

int	the_free(t_data *data, int i)
{
	if (i == 1)
	{
		free(data->fork);
		write(1, "Fork Malloc Error\n", 18);
	}
	else if (i == 2)
	{
		free(data->fork);
		free(data->philo);
		write(1, "Philo Malloc Error\n", 19);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	init_all(&data);
	if (get_argue(&data, argv) == -1)
		return (write(1, "Error\n", 6));
	if (!create_fork(&data))
		return (the_free(&data, 1));
	if (argc == 5)
	{
		if (!create_thread(&data))
			return (the_free(&data, 2));
	}
	if (argc == 6)
	{
		data.num_of_eat = ft_atoi(argv[5]) * data.num_of_philo;
		if (data.num_of_eat < 0)
			return (write(1, "Error\n", 6));
		if (!create_thread(&data))
			return (the_free(&data, 2));
	}
	i = 0;
	while (i < data.num_of_philo)
	{
		pthread_join(data.philo[i], 0);
		i++;
	}
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	data.num_of_philo = 5;
// 	create_thread(&data);
// 	int	i = 0;
// 	while (i < data.num_of_philo)
// 	{
// 		pthread_join(data.philo[i], 0);
// 		i++;
// 	}
// }
