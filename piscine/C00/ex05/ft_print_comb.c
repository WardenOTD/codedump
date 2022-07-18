/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:59:17 by jteoh             #+#    #+#             */
/*   Updated: 2022/05/22 11:27:19 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
char	g_front;
char	g_mid;
char	g_back;

void	ft_print_comb(void)
{
	g_front = '0';
	while (g_front <= '9')
	{
		g_mid = g_front + 1;
		while (g_mid <= '9')
		{
			g_back = g_mid + 1;
			while (g_back <= '9')
			{
				ft_putchar(g_front);
				ft_putchar(g_mid);
				ft_putchar(g_back);
				if (g_front != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				g_back++;
			}
			g_mid++;
		}
		g_front++;
	}
	ft_putchar('\n');
}
