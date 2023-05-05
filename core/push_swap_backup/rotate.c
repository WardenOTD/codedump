/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:49 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/05 15:36:39 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->a[0] == 0)
		return ;
	i = 0;
	tmp = stack->a[i];
	while (stack->a[i + 1] != 0)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	printf("ra\n");
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->b[0] == 0)
		return ;
	i = 0;
	tmp = stack->b[i];
	while (stack->b[i + 1] != 0)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	printf("rb\n");
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	printf("rr\n");
}
