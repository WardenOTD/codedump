/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:36:14 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 14:31:17 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *st, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (st[i] > st[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	bbzero(int *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
}

void	dead(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	full_free(stack);
	exit (1);
}
