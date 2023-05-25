/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:57 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 14:26:11 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	innit_1_help(t_stack *stack, int space)
{
	stack->size = space + 1;
	stack->a = (int *)malloc(sizeof(int) * stack->size);
	stack->b = (int *)malloc(sizeof(int) * stack->size);
	stack->a_size = stack->size;
	stack->b_size = 0;
	bbzero(stack->a, stack->size);
	bbzero(stack->b, stack->size);
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
