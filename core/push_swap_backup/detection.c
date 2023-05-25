/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:06:31 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 11:21:47 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	detect_alph(const char *str, t_stack *stack)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_isalpha(str[i]) == 1 || ft_isdigit(str[i] == 0))
			dead(stack);
		i++;
	}
}

void	only_negative(const char *str, t_stack *stack)
{
	int	i;
	int	count;
	int	neg;

	i = 0;
	count = 0;
	neg = 0;
	while (str[i] != 0)
	{
		if (str[i] == '-')
			neg++;
		else if (ft_isdigit(str[i]))
			count++;
		i++;
	}
	if (neg > 1 || count == 0)
		dead(stack);
}

void	is_negative(int c, t_stack *stack)
{
	if (c == '-')
		dead(stack);
}

void	detect_dupe(t_stack *stack)
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
				dead(stack);
			j++;
		}
		i++;
	}
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
