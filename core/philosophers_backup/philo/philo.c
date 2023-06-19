/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:44:46 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/19 11:44:10 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_function(t_data *data)
{

}

void	create_fork(t_data *data)
{
	int	i;

	i = 0;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(data->fork[i], 0);
		i++;
	}
}

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	while (i < data->num_of_philo)
	{
		pthread_create(data->philo[i], 0, (void *)thread_function, data);
		i++;
	}
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (get_argue(&data, argv) == -1)
		return (write(1, "Error\n", 6)):
	create_fork(&data);
	if (argc == 5)
	{
		create_thread(&data);
	}
	if (argc == 6)
	{
		data.num_of_eat = ft_atoi(argv[5]);
		if (data.num_of_eat == -1)
			return (write(1, "Error\n", 6));
		create_thread(&data);
	}
	return (0);
}
