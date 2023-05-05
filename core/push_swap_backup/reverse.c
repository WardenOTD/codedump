/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:50 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/05 15:58:39 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->a[0] == 0)
		return ;
	i = 0;
	while (stack->a[i + 1] != 0)
		i++;
	tmp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	printf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->b[0] == 0)
		return ;
	i = 0;
	while (stack->b[i + 1] != 0)
		i++;
	tmp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	printf("rrb\n");
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	printf("rrr\n");
}
