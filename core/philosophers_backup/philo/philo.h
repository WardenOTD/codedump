/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:44:42 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/19 11:38:18 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data{
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	int				num_of_philo;
	int				num_of_eat;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
}				t_data;

//_____UTIL.C_____
int	ft_isdigit(int c);

int	ft_atoi(const char *str);

#endif
