/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:20:42 by jteoh             #+#    #+#             */
/*   Updated: 2022/06/08 12:29:39 by jteoh            ###   ########.fr       */
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

	p = 1;
	i = 0;
	if (argc > 1)
	{
		while (p < argc)
		{
			ft_putchar(argv[p][i]);
			i++;
			if (argv[p][i] == '\0')
			{
				ft_putchar('\n');
				p++;
				i = 0;
			}
		}
	}
	return (0);
}
