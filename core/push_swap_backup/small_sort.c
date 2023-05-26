/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:57 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/26 16:10:04 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(int *a)
{
	if (!check_sort(a, 2))
		sa(a, 2);
}

void	sort3(int *a)
{
	while (!check_sort(a, 3))
	{
		if (a[0] > a[2] && a[2] > a[1])
			ra(a, 3);
		else if (a[0] > a[2] && a[1] > a[0])
			rra(a, 3);
		else if (a[2] > a[0] && a[0] > a[1])
			sa(a, 3);
		else if (a[0] > a[1] && a[1] > a[2])
		{
			sa(a, 3);
			rra(a, 3);
		}
		else if (a[2] > a[0] && a[1] > a[2])
		{
			rra(a, 3);
			sa(a, 3);
		}
	}
}

void	sort4(t_stack *stack)
{
	while (stack->a_size > 3)
		pb(stack->a, stack->b, stack);
	sort3(stack->a);
	while (stack->b_size > 0)
		rotate_and_push(stack);
	return ;
}

void	sort5(t_stack *stack)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = bubble_sort_a(stack->a, stack->a_size);
	if (!tmp)
		full_free(stack);
	while (i++ < 5)
	{
		if (tmp[2] > stack->a[0])
			pb(stack->a, stack->b, stack);
		else
			ra(stack->a, stack->a_size);
	}
	sort3(stack->a);
	if (check_sort(stack->b, stack->b_size))
		sb(stack->b, stack->b_size);
	pa(stack->a, stack->b, stack);
	pa(stack->a, stack->b, stack);
	if (!check_sort(stack->a, stack->a_size))
		sort5(stack);
	full_free_tmp(stack, tmp);
	exit (0);
}

void	innit_1_help(t_stack *stack, int space)
{
	stack->size = space + 1;
	stack->a = (int *)malloc(sizeof(int) * stack->size);
	stack->b = (int *)malloc(sizeof(int) * stack->size);
	stack->a_size = stack->size;
	stack->b_size = 0;
	bbzero(stack->a, stack->size);
	bbzero(stack->b, stack->size);
}
