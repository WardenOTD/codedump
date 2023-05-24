/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:26:41 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/24 18:47:33 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack)
{
	if (stack->a_size == 2)
	{
		sort2(stack->a);
		full_free(stack);
	}
	else if (stack->a_size == 3)
	{
		sort3(stack->a);
		full_free(stack);
	}
	else if (stack->a_size == 4)
		sort4(stack);
	else if (stack->a_size == 5)
		sort5(stack);
	else
		radix(stack);
}

void	radix(t_stack *stack)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = bubble_sort_a(stack->a, stack->a_size);
	i = 0;
	while (i < stack->a_size)
	{
		j = 0;
		while (j < stack->a_size)
		{
			if (stack->a[i] == tmp[j])
			{
				stack->a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	main_component(stack);
	full_free_tmp(stack, tmp);
}

void	main_component(t_stack *stack)
{
	int	i;
	int	bitshit;

	bitshit = 0;
	while (!check_sort(stack->a, stack->a_size))
	{
		i = 0;
		while (i < stack->size)
		{
			if (((stack->a[0] >> bitshit) & 1) == 0)
				pb(stack->a, stack->b, stack);
			else
				ra(stack->a, stack->a_size);
			i++;
		}
		while (stack->b_size)
			pa(stack->a, stack->b, stack);
		bitshit++;
	}
}

void	full_free(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
}

void	full_free_tmp(t_stack *stack, int *tmp)
{
	free(stack->a);
	free(stack->b);
	free(tmp);
}
