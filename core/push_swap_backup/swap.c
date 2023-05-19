/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:12:38 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/19 12:34:24 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack *stack)
{
	if (stack->a_size > 0)
	{
		swap(&stack->a[0], &stack->a[1]);
		ft_putstr_fd("sa\n", 1);
	}
	return ;
}

void	sb(t_stack *stack)
{
	if (stack->b_size > 0)
	{
		swap(&stack->b[0], &stack->b[1]);
		ft_putstr_fd("sb\n", 1);
	}
	return ;
}

void	ss(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->a_size > 0)
	{
		swap(&stack->a[0], &stack->a[1]);
		i++;
	}
	if (stack->b_size > 0)
	{
		swap(&stack->b[0], &stack->b[1]);
		i++;
	}
	if (i > 0)
		ft_putstr_fd("ss\n", 1);
}
