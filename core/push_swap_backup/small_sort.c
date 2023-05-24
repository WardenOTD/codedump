/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:57 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/24 18:47:22 by jteoh            ###   ########.fr       */
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
	int	median;
	int	*tmp;
	int	i;

	i = 0;
	median = (stack->a_size / 2);
	tmp = bubble_sort_a(stack->a, stack->a_size);
	if (!tmp)
		full_free(stack);
	while (i < 4)
	{
		if (tmp[median] > stack->a[0])
			pb(stack->a, stack->b, stack);
		else
			ra(stack->a, stack->a_size);
		i++;
	}
	sort2(stack->a);
	sort2(stack->b);
	sb(stack->b, stack->b_size);
	pa(stack->a, stack->b, stack);
	pa(stack->a, stack->b, stack);
	if (!check_sort(stack->a, stack->a_size))
		sort5(stack);
	free(tmp);
	return ;
}

void	sort5(t_stack *stack)
{
	int	median;
	int	*tmp;
	int	i;

	i = 0;
	median = stack->a_size / 2;
	tmp = bubble_sort_a(stack->a, stack->a_size);
	if (!tmp)
		full_free(stack);
	while (i++ < 5)
	{
		if (tmp[median] > stack->a[0])
			pb(stack->a, stack->b, stack);
		else
			ra(stack->a, stack->a_size);
	}
	sort2(stack->b);
	sort3(stack->a);
	sb(stack->b, stack->b_size);
	pa(stack->a, stack->b, stack);
	pa(stack->a, stack->b, stack);
	if (!check_sort(stack->a, stack->a_size))
		sort5(stack);
	free(tmp);
	return ;
}
