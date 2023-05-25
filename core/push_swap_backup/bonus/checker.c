/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:59:22 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 14:49:35 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	act(t_stack *bonus, char *input)
{
	if (ft_strncmp(input, "sa", 2) == 0)
		sa(bonus->a, bonus->a_size);
	if (ft_strncmp(input, "sb", 2) == 0)
		sb(bonus->b, bonus->b_size);
	if (ft_strncmp(input, "ss", 2) == 0)
		ss(bonus->a, bonus->b, bonus->a_size, bonus->b_size);
	if (ft_strncmp(input, "pa", 2) == 0)
		pa(bonus->a, bonus->b, bonus);
	if (ft_strncmp(input, "pb", 2) == 0)
		pb(bonus->a, bonus->b, bonus);
	if (ft_strncmp(input, "ra", 2) == 0)
		ra(bonus->a, bonus->a_size);
	if (ft_strncmp(input, "rb", 2) == 0)
		rb(bonus->b, bonus->b_size);
	if (ft_strncmp(input, "rr", 2) == 0)
		rr(bonus->a, bonus->b, bonus->a_size, bonus->b_size);
	if (ft_strncmp(input, "rra", 2) == 0)
		rra(bonus->a, bonus->a_size);
	if (ft_strncmp(input, "rrb", 2) == 0)
		rrb(bonus->b, bonus->b_size);
	if (ft_strncmp(input, "rrr", 2) == 0)
		rrr(bonus->a, bonus->b, bonus->a_size, bonus->b_size);
}

void	get_input(t_stack *bonus)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			break ;
		act(bonus, input);
	}
	if (check_sort(bonus->a, bonus->a_size) && bonus->b_size == 0)
	{
		ft_putstr_fd("OK\n", 1);
		free(input);
		free(bonus->a);
		free(bonus->b);
		exit (0);
	}
	ft_putstr_fd("KO\n", 2);
	free(input);
	free(bonus->a);
	free(bonus->b);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_stack	bonus;

	if (argc == 2)
	{
		innit_1(argv[1], &bonus);
		if (create_stack_1(argv[1], &bonus) == 0)
			dead(&bonus);
		get_input(&bonus);
		return (0);
	}
	else if (argc > 2)
	{
		bonus.size = argc - 1;
		innit_2(&bonus);
		if (create_stack_2(argv, &bonus) == 0)
			dead(&bonus);
		get_input(&bonus);
		return (0);
	}
	return (0);
}
