/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:36:14 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/19 15:25:57 by jteoh            ###   ########.fr       */
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

void	sort2(t_stack *stack)
{
	if (!check_sort(stack->a, 2))
		sa(stack);
}

void	sort3(t_stack *stack)
{
	while (!check_sort(stack->a, 3))
	{
		if (stack->a[0] > stack->a[2] && stack->a[2] > stack->a[1])
			ra(stack);
		else if (stack->a[0] > stack->a[2] && stack->a[1] > stack->a[0])
			rra(stack);
		else if (stack->a[2] > stack->a[0] && stack->a[0] > stack->a[1])
			sa(stack);
		else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
		{
			sa(stack);
			rra(stack);
		}
		else if (stack->a[2] > stack->a[0] && stack->a[1] > stack->a[2])
		{
			rra(stack);
			sa(stack);
		}
	}
}

void	sort5(t_stack *stack)
{
	int	median;
	int	*tmp;
	int	i;
	int	j;

	median = stack->a_size / 2;
	tmp = bubble_sort_a(stack);
	while (i < stack->a_size)
	{
		if (tmp[median] < stack->a[i])
			pb(stack);
	}
}

int	*bubble_sort_a(t_stack *stack)
{
	int	*tmp;
	int	i;

	tmp = stack_dupe(stack->a, stack->a_size);
	while(!check_sort(tmp, stack->a_size))
	{
		i = 0;
		while (i < (stack->a_size - 1))
		{
			if (tmp[i] > tmp[i + 1])
				swap(&tmp[i], &tmp[i + 1]);
			i++;
		}
	}
	return (tmp);
}

int	*stack_dupe(int *arr, int size)
{
	int	*dup;

	dup = (int *)malloc(sizeof(int) * size);
	size--;
	while (size >= 0)
	{
		dup[size] = arr[size];
		size--;
	}
	return (dup);
}

//	I don't know what the fuck is happening here I'm going insane
