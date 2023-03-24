/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:51:17 by jteoh             #+#    #+#             */
/*   Updated: 2023/03/24 17:14:26 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include <stdio.h>

void	sig(int sig, siginfo_t *info, void *bruh)
{
	static int	bit = 0;
	static int	count = 0;

	(void)bruh;
	if (sig == SIGUSR1)
		bit |= 0;
	if (sig == SIGUSR2)
		bit |= 1;
	if (++count < 8)
		bit <<= 1;
	if ((bit & 255) == 255 && count == 8)
	{
		kill(info->si_pid, SIGUSR1);
		count = 0;
		bit = 0;
	}
	if (count == 8)
	{
		write(1, &bit, 1);
		count = 0;
		bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	cringe;

	cringe.sa_sigaction = sig;
	cringe.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &cringe, NULL);
	sigaction(SIGUSR2, &cringe, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
	}
	return (0);
}
