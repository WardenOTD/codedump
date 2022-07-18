/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print4n4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:44:28 by jteoh             #+#    #+#             */
/*   Updated: 2022/05/28 11:26:28 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_type(int n, int *num, int pos);
void	ft_increment(int n, int *num);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	int	num[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	else
	{
		i = 0;
		while (i < n)
		{
			num[i] = i;
			i++;
		}
		ft_type(n, num, 0);
		while (num[0] != 5 - n || num[n - 1] != 4)
		{
			if (num[n - 1] != 4)
				num[n - 1] += 1;
			else
				ft_increment(n, num);
			ft_type(n, num, 1);
		}
	}
	ft_putchar('\n');
}

void	ft_type(int n, int *num, int pos)
{
	int	i;

	if (pos == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	i = 0;
	while (i < n)
	{
		ft_putchar(num[i] + '0');
		i++;
	}
}

void	ft_increment(int n, int *num)
{
	int	i;
	int	max;

	i = n - 1;
	max = 4;
	while (num[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	num[i] += 1;
	while (i < n)
	{
		num[i + 1] = num[i] + 1;
		i += 1;
	}
}
