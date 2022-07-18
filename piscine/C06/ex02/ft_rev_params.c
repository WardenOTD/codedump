/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:32:15 by jteoh             #+#    #+#             */
/*   Updated: 2022/06/08 12:37:03 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	p;

	i = 0;
	p = argc - 1;
	if (argc > 1)
	{
		while (p > 0)
		{
			ft_putchar(argv[p][i]);
			i++;
			if (argv[p][i] == '\0')
			{
				ft_putchar('\n');
				p--;
				i = 0;
			}
		}
	}
	return (0);
}
