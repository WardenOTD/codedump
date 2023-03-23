/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:51:14 by jteoh             #+#    #+#             */
/*   Updated: 2023/03/23 17:38:51 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	binary(int pid, char *str)
{
	int	num;
	int	bit;
	int	power;
	int	count;

	num = ft_atoi(str);
	bit = 8;
	while (bit > 0)
	{
		power = 2;
		count = bit;
		if (bit == 1)
			power = 1;
		while (count-- > 2)
			power *= 2;
		if (num / power == 0)
			kill(pid, SIGUSR1);
		else if (num / power == 1)
			kill(pid, SIGUSR2);
		num %= power;
		bit--;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		binary(pid, argv[2]);
	}
	return (0);
}
