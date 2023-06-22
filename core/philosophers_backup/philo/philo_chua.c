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

//  -fsanitize=thread -g3
//  gcc -Wall -Wextra -Werror philo_chua.c thread_stuff.c util.c -o philo
//  ./philo 4 410 200 200 7 > test.txt
// 12/30 [40%] chance for a philosopher to kill itself

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

int	last_n_cur_eat(t_data *data)
{
	data->cur_eat_count = (int *)malloc(sizeof(int) * data->num_of_philo);
	data->time_last_eat = (unsigned long *)malloc(sizeof(unsigned long) * data->num_of_philo);
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
		pthread_create(&data->philo[data->id], 0, (void *) thread_func, (void *)data);
		time_start(data);
		usleep(100);
		data->id++;
	}
	data->idmax = --data->id;
	data->death = 0;
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
	data->need_eat	= 0;
	data->time_die = 0;
	data->time_eat = 0;
	data->time_sleep = 0;
	data->death = 1;
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
	else if (i == 3)
	{
		free(data->fork);
		free(data->philo);
		free(data->time_last_eat);
		free(data->cur_eat_count);
	}
	else if (i == 4)
	{
		free(data->fork);
		free(data->time_last_eat);
		free(data->cur_eat_count);
		write(1, "Malloc Error\n", 13);
	}
	return (0);
}

int	eat_check(t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < data->num_of_philo)
	{
		if (data->cur_eat_count[i] == data->num_of_eat)
			flag++;
		i++;
	}
	if (flag == data->num_of_philo)
		return (1);
	return (0);
}

void	you_die(t_data *data, int i)
{
	if (!eat_check(data) || !data->need_eat)
	{
		time_end(data);
		printf("%lu %d has died\n", data->tod_end, i + 1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	time_end(&data);
	while (data.death == 0)
	{
		while ((data.tod_end - data.time_last_eat[i]) < data.time_die)
		{
			if (i == data.idmax)
			{
				usleep(data.death * 1000);
				i = -1;
			}
			i++;
			time_end(&data);
		}
		data.death = 1;
	}
	you_die(&data, i);
	while (j < data.num_of_philo)
	{
		pthread_join(data.philo[j], 0);
		pthread_mutex_destroy(&data.fork[j]);
		j++;
	}
	the_free(&data, 3);
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

// while (data.death == 0)
// {
// 	if (i > data.fidmax)
// 		i = 0;
// 	if (data.time_last_eat[i] > data.time_die)
// 	{
// 		while (j < data.num_of_philo)
// 		{
// 			pthread_join(data.philo[j], 0);
// 			pthread_mutex_destroy(&data.fork[j]);
// 			j++;
// 		}
// 		data.death = 1;
// 		break ;
// 	}
// 	else if (eat_check(&data))
// 	{
// 		while (j < data.num_of_philo)
// 		{
// 			pthread_join(data.philo[j], 0);
// 			pthread_mutex_destroy(&data.fork[j]);
// 			j++;
// 		}
// 		break ;
// 	}
// 	i++;
// }

// while (data.death == 0)
// {
// 	if (i > data.fidmax)
// 		i = 0;
// 	if (data.time_last_eat[i] > data.time_die)
// 	{
// 		while (j < data.num_of_philo)
// 		{
// 			pthread_join(data.philo[j], 0);
// 			pthread_mutex_destroy(&data.fork[j]);
// 			j++;
// 		}
// 		data.death = 1;
// 		break ;
// 	}
// 	i++;
// }
