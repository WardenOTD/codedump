/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:49 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/19 12:08:55 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
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
		ft_putstr_fd("ra\n", 1);
	}
	return ;
}

void	rb(t_stack *stack)
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
		ft_putstr_fd("rb\n", 1);
	}
	return ;
}

void	rr(t_stack *stack)
{
	int	c;
	int	i;

	c = 0;
	if (stack->a_size > 0)
	{
		i = 0;
		while (i < (stack->a_size - 1))
		{
			swap(&stack->a[i], &stack->a[i + 1]);
			i++;
		}
		c++;
	}
	if (stack->b_size > 0)
	{
		i = 0;
		while (i < (stack->b_size - 1))
		{
			swap(&stack->b[i], &stack->b[i + 1]);
			i++;
		}
		c++;
	}
	if (c > 0)
		ft_putstr_fd("rr\n", 1);
}
