/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:44:42 by jteoh             #+#    #+#             */
/*   Updated: 2023/06/23 16:47:06 by jteoh            ###   ########.fr       */
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
	pthread_mutex_t	*get_last_eaten;
	pthread_mutex_t	*fork;
	int				id;
	int				idmax;
	int				fid;
	int				fidmax;
	unsigned long	tod_start;

	pthread_mutex_t	death_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	lock_thread;

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

typedef struct s_philo
{
	int				id;
	int				holded_fork;

	unsigned long	num_of_eat;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
}			t_philo;

typedef struct s_fock{
	int				l_id;
	int				r_id;
}				t_fock;

//_____PHILO.C_____
void			init_all(t_data *data);

int				the_free(t_data *data, int i);

void			main3(t_data *data, int i, unsigned long ded, int idm);

void			main2(t_data *data, int i, int j);

int				main(int argc, char **argv);

//_____CREATION.C_____
int				get_argue(t_data *data, char **av);

int				create_fork(t_data *data);

int				last_n_cur_eat(t_data *data);

int				create_thread(t_data *data);

//_____THREAD_STUFF.C_____
int				eat(t_data *data, t_philo ref, t_fock fock);

int				sleeep(t_data *data, t_philo ref);

int				fouck(t_data *data, t_philo ref, t_fock fock);

void			thread_func2(t_data *data, t_philo ref, t_fock fock);

void			thread_func(void *stuff);

//_____UTIL.C_____
int				ft_isdigit(int c);

int				ft_atoi(const char *str);

void			time_start(t_data *data);

unsigned long	time_end(t_data *data);

int				eat_check(t_data *data);

//_____UTIL2.C_____
void			you_die(t_data *data, int i);

void			toggle_death(t_data *data);

int				print_time_stamp(t_data *data, char *line,
					unsigned long time, int id);

void			init_thread_stuff(t_data *data, t_philo *ref, t_fock *fock);

#endif
