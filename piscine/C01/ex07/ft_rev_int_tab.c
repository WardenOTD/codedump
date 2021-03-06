/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:24:42 by jteoh             #+#    #+#             */
/*   Updated: 2022/05/25 16:06:28 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = size - 1;
	while (i < size / 2)
	{
		y = tab[i];
		tab[i] = tab[x];
		tab[x] = y;
		i++;
		x--;
	}
}
