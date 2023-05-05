/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:48 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/05 15:36:10 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->b[0] == 0)
		return ;
	i = 0;
	tmp = stack->b[0];
	while (stack->b[i + 1] != 0)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = 0;
	i = 0;
	while (stack->a[i] != 0)
		i++;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
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
	while (stack->a[i + 1] != 0)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = 0;
	i = 0;
	while (stack->b[i] != 0)
		i++;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	printf("pb\n");
}
