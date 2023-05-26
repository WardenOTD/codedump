/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:34:27 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/26 16:10:00 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	innit_1(char *tmp, t_stack *stack)
{
	int	count;
	int	space;

	space = 0;
	count = 0;
	while (tmp[count] != 0)
	{
		if (tmp[count] == ' ')
		{
			if (tmp[count] == ' ' && count == 0)
			{
				count++;
				continue ;
			}
			else if (tmp[count - 1] != ' ')
				space++;
		}
		count++;
	}
	innit_1_help(stack, space);
}

void	innit_2(t_stack *stack)
{
	stack->a = (int *)malloc(sizeof(int) * stack->size);
	stack->b = (int *)malloc(sizeof(int) * stack->size);
	stack->a_size = stack->size;
	stack->b_size = 0;
	bbzero(stack->a, stack->size);
	bbzero(stack->b, stack->size);
}

int	create_stack_1(char *argv, t_stack *stack)
{
	char	**tmp;
	int		i;

	tmp = ft_split(argv, ' ');
	if (tmp == NULL)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		stack->a[i] = modify_atoi(tmp[i], stack);
		i++;
	}
	free2d(tmp);
	detect_dupe(stack);
	return (1);
}

int	create_stack_2(char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j <= stack->size)
	{
		if (detect_space(argv[j]) == 0)
			return (0);
		stack->a[i++] = modify_atoi(argv[j++], stack);
	}
	detect_dupe(stack);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 1 && argv[1] == NULL)
		exit (0);
	if (argc == 2)
	{
		innit_1(argv[1], &stack);
		if (create_stack_1(argv[1], &stack) == 0)
			dead(&stack);
		sort(&stack);
		exit (0);
	}
	else if (argc > 2)
	{
		stack.size = argc - 1;
		innit_2(&stack);
		if (create_stack_2(argv, &stack) == 0)
			dead(&stack);
		sort(&stack);
		exit (0);
	}
	return (0);
}
