/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:50 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/24 18:18:32 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *a, int size)
{
	int	i;

	if (size > 0)
	{
		i = size - 2;
		while (i >= 0)
		{
			swap(&a[i], &a[i + 1]);
			i--;
		}
		ft_putstr_fd("rra\n", 1);
	}
	return ;
}

void	rrb(int *b, int size)
{
	int	i;

	if (size > 0)
	{
		i = size - 2;
		while (i >= 0)
		{
			swap(&b[i], &b[i + 1]);
			i--;
		}
		ft_putstr_fd("rrb\n", 1);
	}
	return ;
}

void	rrr(int *a, int *b, int a_size, int b_size)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (a_size > 0)
	{
		i = a_size - 2;
		while (i >= 0)
		{
			swap(&a[i], &a[i + 1]);
			i--;
		}
		c++;
	}
	c += rrr_help(b, b_size, i, c);
	if (c > 0)
		ft_putstr_fd("rrr\n", 1);
}

int	rrr_help(int *b, int b_size, int i, int c)
{
	if (b_size > 0)
	{
		i = b_size - 2;
		while (i >= 0)
		{
			swap(&b[i], &b[i + 1]);
			i--;
		}
		c++;
	}
	return (c);
}
