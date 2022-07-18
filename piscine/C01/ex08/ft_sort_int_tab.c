/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:37:19 by jteoh             #+#    #+#             */
/*   Updated: 2022/05/26 11:00:10 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *x, int *tab, int arc);

void	ft_sort_int_tab(int *tab, int size)
{
	int	arc;
	int	swapcount;
	int	x;

	arc = 0;
	swapcount = 0;
	while (swapcount <= (size - 1))
	{
		if (arc == (size - 1) && swapcount != (size - 1))
		{
				arc = 0;
				swapcount = 0;
		}
		else if (tab[arc] > tab[arc + 1])
		{
			swap(&x, tab, arc);
			arc++;
		}
		else if (tab[arc] < tab[arc + 1])
		{
			arc++;
			swapcount++;
		}
	}
}

void	swap(int *x, int *tab, int arc)
{
		*x = tab[arc];
		tab[arc] = tab[arc + 1];
		tab[arc + 1] = *x;
}
