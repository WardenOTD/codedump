/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:48 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/16 15:49:57 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->b_size == 0)
		return ;
	i = 0;
	tmp = stack->b[0];
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = 0;
	i = stack->a_size - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	stack->a_size++;
	stack->b_size--;
	printf("pa\n");
}

void	pb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->a[0] == 0)
		return ;
	i = 0;
	tmp = stack->a[0];
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = 0;
	i = stack->b_size - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	stack->a_size--;
	stack->b_size++;
	printf("pb\n");
}
