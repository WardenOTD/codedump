/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:51:17 by jteoh             #+#    #+#             */
/*   Updated: 2023/03/23 17:37:54 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	sig(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("0\n", 1);
	else if (sig == SIGUSR2)
		ft_putstr_fd("1\n", 1);
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, sig);
	signal(SIGUSR2, sig);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
	}
	return (0);
}
