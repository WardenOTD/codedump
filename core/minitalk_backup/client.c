/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:51:14 by jteoh             #+#    #+#             */
/*   Updated: 2023/03/29 12:33:48 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

void	binary(int pid, char *str)
{
	int	num;
	int	count;

	while (*str)
	{
		num = *str;
		count = -1;
		while (++count < 8)
		{
			if (num & (1 << (7 - count)))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(950);
		}
		str++;
	}
}

void	done(int sig)
{
	if (sig)
		write(1, "\n\n=====done=====\n\n\n", (19 * sizeof(char)));
	exit(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	eof;

	signal(SIGUSR1, done);
	eof = -1;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
		binary(pid, argv[2]);
	while (++eof < 8)
	{
		kill(pid, SIGUSR2);
		usleep(800);
	}
	while (1)
	{
		pause();
	}
}
