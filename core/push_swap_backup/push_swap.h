/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:55:04 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/19 16:44:01 by jteoh            ###   ########.fr       */
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
	int	*b;
	int	a_size;
	int	b_size;
	int	size;
}				t_stack;

void	swap(int *a, int *b);

void	sa(int *a, int size);

void	sb(int *b, int size);

void	ss(int *a, int *b, int a_size, int b_size);

void	pa(int *a, int *b, t_stack *stack);

void	pb(int *a, int *b, t_stack *stack);

void	ra(int *a, int size);

void	rb(int *b, int size);

void	rr(int *a, int *b, int a_size, int b_size);

void	rra(int *a, int size);

void	rrb(int *b, int size);

void	rrr(int *a, int *b, int a_size, int b_size);

int		*stack_dupe(int *arr, int size);

int		*bubble_sort_a(int *arr, int size);

int		check_sort(int *st, int size);

void	sort2(int *a);

void	sort3(int *a);

void	sort4(t_stack *stack);

void	sort5(t_stack *stack);

#endif
