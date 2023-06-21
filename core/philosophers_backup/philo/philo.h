/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:44:42 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/21 12:08:34 by jteoh            ###   ########.fr       */
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
	int				id;
	int				idmax;
	int				fid;
	int				fidmax;
	unsigned long	tod_start;
	unsigned long	tod_end;
	int				num_of_philo;
	int				num_of_eat;
	int				need_eat;
	int				*cur_eat_count;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	*time_last_eat;
	int				death;
}				t_data;

typedef struct s_fock{
	int				l_id;
	int				r_id;
}				t_fock;

//_____UTIL.C_____
int		ft_isdigit(int c);

int		ft_atoi(const char *str);

void	time_start(t_data *data);

void	time_end(t_data *data);

#endif
