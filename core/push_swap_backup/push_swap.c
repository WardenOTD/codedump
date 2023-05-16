/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:34:27 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/16 15:57:54 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bbzero(int *s, int size)
{
	int	i;
	i = 0;
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
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

void	innit_1(char *tmp, t_stack *stack)
{
	int	count;
	int	space;

	space = 0;
	count = 0;
	while (tmp[count] != 0)
	{
		if (tmp[count] == ' ')
			space++;
		count++;
	}
	stack->size = space + 1;
	stack->a = (int *)malloc(sizeof(int) * stack->size);
	stack->b = (int *)malloc(sizeof(int) * stack->size);
	stack->a_size = stack->size;
	stack->b_size = 0;
	bbzero(stack->a, stack->size);
	bbzero(stack->b, stack->size);
}

int	modify_atoi(const char *str)
{
	long	out;
	int		sign;

	sign = 1;
	out = 0;
	while (*str == '\t' || *str == '\f' || *str == '\r'
		|| *str == '\v' || *str == ' ' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (out >= 214748364 && *str > '7' && sign == 1)
		{
			ft_putstr_fd("overflow\n", 2);
			exit (2);
		}
		if (out >= 214748364 && *str > '8' && sign == -1)
		{
			ft_putstr_fd("negative overflow\n", 2);
			exit (2);
		}
		out = out * 10 + (*str - '0');
		str++;
	}
	return ((int)(out * sign));
}

void detect_dupe(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->a[i] == stack->a[j])
			{
				ft_putstr_fd("duplicate number\n", 2);
				exit (2);
			}
			j++;
		}
		i++;
	}
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
		stack->a[i] = modify_atoi(tmp[i]);
		i++;
	}
	detect_dupe(stack);
	return (1);
}

int	detect_space(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		if (argv[i] == ' ')
			return (0);
		i++;
	}
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
		stack->a[i++] = modify_atoi(argv[j++]);
	}
	detect_dupe(stack);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.size = 0;
	if (argc == 2)
	{
		innit_1(argv[1], &stack);
		if (create_stack_1(argv[1], &stack) == 0)
		{
			ft_putstr_fd("split / malloc error\n", 2); //need free
			exit (2);
		}
		pb(&stack);
		pa(&stack);
		pb(&stack);
		pb(&stack);
		ss(&stack);
		rr(&stack);
		rrr(&stack);
		for (int i = 0; i < stack.size; i++)
		{
			printf("%d  ", stack.a[i]);
			printf("%d\n", stack.b[i]);
		}
		return (0);
	}
	else if (argc > 2)
	{
		stack.size = argc - 1;
		innit_2(&stack);
		if (create_stack_2(argv, &stack) == 0)
		{
			ft_putstr_fd("invalid argument\n", 2); //need free
			exit (2);
		}
		pb(&stack);
		pa(&stack);
		pb(&stack);
		pb(&stack);
		ss(&stack);
		rr(&stack);
		rrr(&stack);
		for (int i = 0; i < stack.size; i++)
		{
			printf("%d  ", stack.a[i]);
			printf("%d\n", stack.b[i]);
		}
		return (0);
	}
	printf("Invalid arguements\n");
	return (0);
}


//current way of solving push_swap is invalid, complete overhaul is due.
//original idea of converting every number into a list without 0 seems almost impossible.
//new approach, sort the list as is with the numbers given, foregoing all my end checking using 0s.
//ft_atoi return value is a problem, needing to find a way to return a proper error not invloving numbers.
//or recreating a new atoi script using long to detect and handle int overflow so the error value isnt sent into the stack
//blending in with the sea of other integers.
