/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:55:04 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/16 15:55:44 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	int	*a;
	int *b;
	int	a_size;
	int	b_size;
	int	size;
}				t_stack;

void	sa(t_stack *stack);

void	sb(t_stack *stack);

void	ss(t_stack *stack);

void	pa(t_stack *stack);

void	pb(t_stack *stack);

void	ra(t_stack *stack);

void	rb(t_stack *stack);

void	rr(t_stack *stack);

void	rra(t_stack *stack);

void	rrb(t_stack *stack);

void	rrr(t_stack *stack);

#endif
