/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:50 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/19 13:57:26 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		i = stack->a_size - 2;
		while (i >= 0)
		{
			swap(&stack->a[i], &stack->a[i + 1]);
			i--;
		}
		ft_putstr_fd("rra\n", 1);
	}
	return ;
}

void	rrb(t_stack *stack)
{
	int	i;

	if (stack->b_size > 0)
	{
		i = stack->b_size - 2;
		while (i >= 0)
		{
			swap(&stack->b[i], &stack->b[i + 1]);
			i--;
		}
		ft_putstr_fd("rrb\n", 1);
	}
	return ;
}

int	rrr_help(t_stack *stack, int i, int c)
{
	if (stack->b_size > 0)
	{
		i = stack->b_size - 2;
		while (i >= 0)
		{
			swap(&stack->b[i], &stack->b[i + 1]);
			i--;
		}
		c++;
	}
	return (c);
}

void	rrr(t_stack *stack)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (stack->a_size > 0)
	{
		i = stack->a_size - 2;
		while (i >= 0)
		{
			swap(&stack->a[i], &stack->a[i + 1]);
			i--;
		}
		c++;
	}
	c += rrr_help(stack, i, c);
	if (c > 0)
		ft_putstr_fd("rrr\n", 1);
}
