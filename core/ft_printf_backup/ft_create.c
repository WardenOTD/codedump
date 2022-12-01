/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:13:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/01 16:31:36 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out(t_specifier *spc, t_flags *flag, va_list list, const char *str)
{
	char	*cc;
	int		min;

	if (cnc(str, spc, flag) == 0)
		return (0);
	min = minimum(flag);
	flag->output = (char *)malloc(sizeof(char) * (min + 1));
	if (!(flag->output))
		return (0);
	flag->output[min] = 0;
	fillspace(flag);
	if (spc->x == 1 || spc->upperx == 1 || spc->p == 1)
		return (if_hex(flag, spc, list));
	if (spc->c == 1)
		return (if_char(flag, list));
	cc = create_c(spc, list);
	if (!cc)
		return (0);
	cmp(flag, cc);
	other(spc, flag);
	return (1);
}

char	*create_c(t_specifier *spc, va_list list)
{
	char	*cc;

	if (spc->s == 1)
	{
		cc = va_arg(list, char *);
		return (cc);
	}
	if (spc->x == 1 || spc->upperx == 1)
	{
		cc = va_arg(list, char *);
		return (cc);
	}
	if (spc->di == 1 || spc->u == 1)
	{
		cc = va_arg(list, char *);
		return (cc);
	}
	return (0);
}

void	fillspace(t_flags *flag)
{
	int	i;

	i = 0;
	while (flag->output[i] != 0)
		flag->output[i] = ' ';
}

void	cmp(t_flags *flag, char *cc)
{
	int	src;
	int	dest;

	src = ft_strlen(cc);
	dest = ft_strlen(flag->output);
	if (src > dest)
	{
		free(flag->output);
		flag->output = ft_strdup(cc);
		return ;
	}
	if (src < dest)
	{
		if (flag->neg == 1)
		{
			while (*cc != 0)
				*(flag->output++) = *(cc++);
			return ;
		}
		while (src >= 0)
			flag->output[dest--] = cc[src--];
		return ;
	}
}

void	other(t_specifier *spc, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->pos == 1)
	{
		while (flag->output[i] == ' ')
		{
			if (flag->output[i] == '-')
				break ;
			else if (flag->output[i] != ' ')
				flag->output[--i] = '+';
			i++;
		}
	}
	if (flag->hash == 1 || spc->p == 1)
	{
		while (flag->output[i] == ' ')
			i++;
		i--;
		flag->output[i - 1] = '0';
		if (spc->x == 1 || spc->p == 1)
			flag->output[i] = 'x';
		else if (spc->upperx == 1)
			flag->output[i] = 'X';
	}
}
