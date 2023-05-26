/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:12:38 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/26 16:02:44 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(int *a, int size)
{
	if (size > 0)
		swap(&a[0], &a[1]);
	return ;
}

void	sb(int *b, int size)
{
	if (size > 0)
		swap(&b[0], &b[1]);
	return ;
}

void	ss(int *a, int *b, int a_size, int b_size)
{
	int	i;

	i = 0;
	if (a_size > 0)
	{
		swap(&a[0], &a[1]);
		i++;
	}
	if (b_size > 0)
	{
		swap(&b[0], &b[1]);
		i++;
	}
	if (i > 0)
		return ;
}
