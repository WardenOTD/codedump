/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:21:49 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/24 18:18:20 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *a, int size)
{
	int	i;

	if (size > 0)
	{
		i = 0;
		while (i < (size - 1))
		{
			swap(&a[i], &a[i + 1]);
			i++;
		}
		ft_putstr_fd("ra\n", 1);
	}
	return ;
}

void	rb(int *b, int size)
{
	int	i;

	if (size > 0)
	{
		i = 0;
		while (i < (size - 1))
		{
			swap(&b[i], &b[i + 1]);
			i++;
		}
		ft_putstr_fd("rb\n", 1);
	}
	return ;
}

void	rr(int *a, int *b, int a_size, int b_size)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (a_size > 0)
	{
		i = 0;
		while (i < (a_size - 1))
		{
			swap(&a[i], &a[i + 1]);
			i++;
		}
		c++;
	}
	c += rr_help(b, b_size, i, c);
	if (c > 0)
		ft_putstr_fd("rr\n", 1);
}

int	rr_help(int *b, int b_size, int i, int c)
{
	if (b_size > 0)
	{
		i = 0;
		while (i < (b_size - 1))
		{
			swap(&b[i], &b[i + 1]);
			i++;
		}
		c++;
	}
	return (c);
}
