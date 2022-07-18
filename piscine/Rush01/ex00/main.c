/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <etlaw@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:52:47 by etlaw             #+#    #+#             */
/*   Updated: 2022/05/29 18:49:32 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str);

int	main(int argc, char *argv[])
{
	if (argc == 2 && ft_strlen(argv[1]) == 31)
	{
		write(1, "0 0 0 0\n", 8);
		write(1, "0 0 0 0\n", 8);
		write(1, "0 0 0 0\n", 8);
		write(1, "0 0 0 0\n", 8);
	}
	else
		write (1, "Error\n", 6);
}
