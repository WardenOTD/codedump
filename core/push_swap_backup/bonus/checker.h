/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:18:36 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 14:50:29 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

//-----CHECKER.C-----
int			main(int argc, char **argv);

void		get_input(t_stack *bonus);

void		act(t_stack *bonus, char *input);

//-----PS_BONUS.C-----
void		innit_1(char *tmp, t_stack *stack);

void		innit_2(t_stack *stack);

int			create_stack_1(char *argv, t_stack *stack);

int			create_stack_2(char **argv, t_stack *stack);

//-----ATOI_BONUS.C-----
int			modify_atoi(const char *str, t_stack *stack);

int			modify_atoi_half(const char *str, t_stack *stack,
				long out, int sign);

//-----DETC_BONUS.C-----
void		detect_alph(const char *str, t_stack *stack);

void		only_negative(const char *str, t_stack *stack);

void		is_negative(int c, t_stack *stack);

void		detect_dupe(t_stack *stack);

int			detect_space(char *argv);

//-----EXTRA_BONUS.C-----
void		innit_1_help(t_stack *stack, int space);

void		full_free(t_stack *stack);

void		full_free_tmp(t_stack *stack, int *tmp);

//-----UTILS_BONUS.C-----
int			check_sort(int *st, int size);

void		bbzero(int *s, int size);

void		dead(t_stack *stack);

//-----SWAP_BONUS.C-----
void		swap(int *a, int *b);

void		sa(int *a, int size);

void		sb(int *b, int size);

void		ss(int *a, int *b, int a_size, int b_size);

//-----PUSH_BONUS.C-----
void		pa(int *a, int *b, t_stack *stack);

void		pb(int *a, int *b, t_stack *stack);

//-----ROTATE_BONUS.C-----
void		ra(int *a, int size);

void		rb(int *b, int size);

void		rr(int *a, int *b, int a_size, int b_size);

int			rr_help(int *b, int b_size, int i, int c);

//-----reverse_BONUS.C-----
void		rra(int *a, int size);

void		rrb(int *b, int size);

void		rrr(int *a, int *b, int a_size, int b_size);

int			rrr_help(int *b, int b_size, int i, int c);

#endif
