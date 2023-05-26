/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:12:49 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/26 16:10:14 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	find_index_max( int *arr, int size)
{
	int		i;
	int		max;
	int		index;

	i = 0;
	max = arr[0];
	index = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	rotate_and_push(t_stack *stack)
{
	int		i;
	int		imax;

	i = 0;
	while (stack->b[0] > stack->a[i] && i < stack->a_size)
		i++;
	imax = find_index_max(stack->a, stack->a_size);
	if (i < imax)
		while (i--)
			ra(stack->a, stack->a_size);
	else
		while (i++ < stack->a_size)
			rra(stack->a, stack->a_size);
	pa(stack->a, stack->b, stack);
	imax = find_index_max(stack->a, stack->a_size);
	while (!check_sort(stack->a, stack->a_size))
	{
		if (imax >= stack->a_size / 2)
			rra(stack->a, stack->a_size);
		else
			ra(stack->a, stack->a_size);
	}
	full_free(stack);
	exit (0);
}
