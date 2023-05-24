/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:36:14 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/24 18:47:59 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *st, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (st[i] > st[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*bubble_sort_a(int *arr, int size)
{
	int	*tmp;
	int	i;

	tmp = stack_dupe(arr, size);
	if (!tmp)
		return (0);
	while (!check_sort(tmp, size))
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tmp[i] > tmp[i + 1])
				swap(&tmp[i], &tmp[i + 1]);
			i++;
		}
	}
	return (tmp);
}

int	*stack_dupe(int *arr, int size)
{
	int	*dup;

	dup = (int *)malloc(sizeof(int) * size);
	if (!dup)
		return (0);
	size--;
	while (size >= 0)
	{
		dup[size] = arr[size];
		size--;
	}
	return (dup);
}

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
