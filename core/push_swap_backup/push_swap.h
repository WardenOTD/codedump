/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:55:04 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 12:09:27 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
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

typedef struct s_bonus {
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
	int	size;
}				t_bonus;

//-----PUSH_SWAP.C-----
int			main(int argc, char **argv);

void		innit_1(char *tmp, t_stack *stack);

void		innit_2(t_stack *stack);

int			create_stack_1(char *argv, t_stack *stack);

int			create_stack_2(char **argv, t_stack *stack);

//-----SORT.C-----
void		sort(t_stack *stack);

void		radix(t_stack *stack);

void		main_component(t_stack *stack);

void		full_free(t_stack *stack);

void		full_free_tmp(t_stack *stack, int *tmp);

//-----MODIFY_ATOI.C-----
int			modify_atoi(const char *str, t_stack *stack);

int			modify_atoi_half(const char *str, t_stack *stack,
				long out, int sign);

//-----DETECTION.C-----
void		detect_alph(const char *str, t_stack *stack);

void		only_negative(const char *str, t_stack *stack);

void		is_negative(int c, t_stack *stack);

void		detect_dupe(t_stack *stack);

int			detect_space(char *argv);

//-----SMALL_SORT.C-----
void		sort2(int *a);

void		sort3(int *a);

void		sort4(t_stack *stack);

void		sort5(t_stack *stack);

void		innit_1_help(t_stack *stack, int space);

//-----UTILS.C-----
int			check_sort(int *st, int size);

int			*bubble_sort_a(int *arr, int size);

int			*stack_dupe(int *arr, int size);

void		bbzero(int *s, int size);

void		dead(t_stack *stack);

//-----SWAP.C-----
void		swap(int *a, int *b);

void		sa(int *a, int size);

void		sb(int *b, int size);

void		ss(int *a, int *b, int a_size, int b_size);

//-----PUSH.C-----
void		pa(int *a, int *b, t_stack *stack);

void		pb(int *a, int *b, t_stack *stack);

//-----ROTATE.C-----
void		ra(int *a, int size);

void		rb(int *b, int size);

void		rr(int *a, int *b, int a_size, int b_size);

int			rr_help(int *b, int b_size, int i, int c);

//-----reverse.C-----
void		rra(int *a, int size);

void		rrb(int *b, int size);

void		rrr(int *a, int *b, int a_size, int b_size);

int			rrr_help(int *b, int b_size, int i, int c);

#endif
