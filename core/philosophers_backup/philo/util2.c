/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:41:35 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/23 16:44:09 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	you_die(t_data *data, int i)
{
	unsigned long	time;

	time = time_end(data);
	if (!eat_check(data) || !data->need_eat)
		printf("%lu %d has died\n", time, i + 1);
}

void	toggle_death(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	data->death = 1;
	pthread_mutex_unlock(&data->death_lock);
}

int	print_time_stamp(t_data *data, char *line, unsigned long time, int id)
{
	int	wait;

	pthread_mutex_lock(&data->death_lock);
	wait = data->death;
	pthread_mutex_unlock(&data->death_lock);
	if (wait)
		return (-1);
	return (printf(line, time, id));
}

void	init_thread_stuff(t_data *data, t_philo *ref, t_fock *fock)
{
	pthread_mutex_lock(&data->lock_thread);
	ref->id = data->id;
	data->cur_eat_count[ref->id] = 0;
	data->time_last_eat[ref->id] = 0;
	if (ref->id == 0)
		fock->l_id = data->fidmax;
	else
		fock->l_id = ref->id - 1;
	fock->r_id = ref->id;
	ref->num_of_eat = data->num_of_eat;
	ref->time_die = data->time_die;
	ref->time_eat = data->time_eat;
	ref->time_sleep = data->time_sleep;
	pthread_mutex_unlock(&data->lock_thread);
	ref->holded_fork = 0;
}
