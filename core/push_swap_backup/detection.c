/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:06:31 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/24 18:07:19 by jteoh            ###   ########.fr       */
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
		{
			ft_putstr_fd("invalid number\n", 2);
			full_free(stack);
			exit (1);
		}
		i++;
	}
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
			{
				ft_putstr_fd("duplicate number\n", 2);
				full_free(stack);
				exit (1);
			}
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
