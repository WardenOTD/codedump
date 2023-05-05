/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:12:38 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/05 15:14:22 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->a[0] == 0 || stack->a[1] == 0)
		return ;
	tmp = stack->a[1];
	stack->a[1] = stack->a[0];
	stack->a[0] = tmp;
	printf("sa\n");
}

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->b[0] == 0 || stack->b[1] == 0)
		return ;
	tmp = stack->b[1];
	stack->b[1] = stack->b[0];
	stack->b[0] = tmp;
	printf("sb\n");
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	printf("ss\n");
}
