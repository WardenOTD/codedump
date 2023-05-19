/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:48 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/19 12:32:41 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	i;

	if (stack->b_size > 0)
	{
		i = 0;
		while (i < (stack->b_size - 1))
		{
			swap(&stack->b[i], &stack->b[i + 1]);
			i++;
		}
		i = stack->a_size - 1;
		while (i >= 0)
		{
			swap(&stack->a[i], &stack->a[i + 1]);
			i--;
		}
		stack->a[0] = stack->b[stack->b_size - 1];
		stack->b[stack->b_size - 1] = 0;
		stack->a_size++;
		stack->b_size--;
		ft_putstr_fd("pa\n", 1);
	}
	return ;
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		i = 0;
		while (i < (stack->a_size - 1))
		{
			swap(&stack->a[i], &stack->a[i + 1]);
			i++;
		}
		i = stack->b_size - 1;
		while (i >= 0)
		{
			swap(&stack->b[i], &stack->b[i + 1]);
			i--;
		}
		stack->b[0] = stack->a[stack->a_size - 1];
		stack->a[stack->a_size - 1] = 0;
		stack->b_size++;
		stack->a_size--;
		ft_putstr_fd("pb\n", 1);
	}
	return ;
}
