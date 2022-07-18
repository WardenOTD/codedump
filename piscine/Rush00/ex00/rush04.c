/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:40:53 by zwong             #+#    #+#             */
/*   Updated: 2022/05/22 11:04:28 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);
char	generate_char(int row_num, int col_num, int y, int x);
char	corner_char(int row_num, int col_num, int y, int x);
char	edge_char(int row_num, int col_num, int y, int x);

void	rush(int x, int y)
{
	int		row_num;
	int		col_num;
	char	putchar_result;

	row_num = 1;
	col_num = 1;
	if (x <= 0 || y <= 0)
		write(1, "please input valid number\n", 26);
	else
	{
		while (row_num <= y)
		{
			while (col_num <= x)
			{
				putchar_result = generate_char(row_num, col_num, y, x);
				ft_putchar(putchar_result);
				++col_num;
			}
			col_num = 1;
			ft_putchar('\n');
			++row_num;
		}
	}
}

char	generate_char(int row_num, int col_num, int y, int x)
{
	if ((row_num == 1 && col_num == 1) || (row_num == 1 && col_num == x))
	{
		return (corner_char(row_num, col_num, y, x));
	}
	else if ((row_num == y && col_num == 1) || (row_num == y && col_num == x))
	{
		return (corner_char(row_num, col_num, y, x));
	}
	else if (row_num == 1 || row_num == y || col_num == 1 || col_num == x)
	{
		return (edge_char(row_num, col_num, y, x));
	}
	else
	{
		return (' ');
	}
}

char	corner_char(int row_num, int col_num, int y, int x)
{
	if (row_num == 1 && col_num == 1)
	{
		return ('A');
	}
	else if (row_num == 1 && col_num == x)
	{
		return ('C');
	}
	else if (row_num == y && col_num == 1)
	{
		return ('C');
	}
	else if (row_num == y && col_num == x)
	{
		return ('A');
	}
	else
	{
		return (0);
	}
}

char	edge_char(int row_num, int col_num, int y, int x)
{
	if (row_num == 1 || row_num == y)
	{
		return ('B');
	}
	else if (col_num == 1 || col_num == x)
	{
		return ('B');
	}
	else
	{
		return (0);
	}
}
