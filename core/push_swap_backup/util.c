/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:36:14 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/19 13:47:27 by jteoh            ###   ########.fr       */
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
