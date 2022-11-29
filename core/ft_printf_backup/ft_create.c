/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:13:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/11/29 17:11:51 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out(t_specifier *spc, t_flags *flag, va_list list, const char *str)
{
	char	c;
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
	if (spc->c == 1)
		c = va_arg(list, char);
	cc = create_c(spc, flag, list);
	if (!cc)
		return (0);
	//call smtg else
	cmp(flag, cc);
	other(spc, flag);
	return ;
}

char	*create_c(t_specifier *spc, t_flags *flag, va_list list)
{
	char	*cc;

	if (spc->s == 1)
	{
		cc = va_arg(list, char *);
		return (cc);
	}
	if (spc->p == 1)
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

void	cmp(t_flags *flag, char *cc)
{
	int	src;
	int	dest;
	int	i;
	int	j;

	src = ft_strlen(cc);
	dest = ft_strlen(flag->output);
	if (src > dest)
	{
		free(flag->output);
		flag->output = cc;
		return ;
	}
	if (src < dest)
	{
		if (flag->neg == 1)
		{
			while (cc[j] != 0)
				flag->output[i++] = cc[j++];
			return ;
		}
		while (src >= 0)
			flag->output[dest--] = cc[src--];
		return ;
	}
}

void	fillspace(t_flags *flag)
{
	int	i;

	i = 0;
	while (flag->output[i] != 0)
		flag->output[i] = ' ';
}

void	other(t_specifier *spc, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->pos == 1)
	{
		while (flag->output[i] != ' ')
		{
			if (flag->output[i] == '-')
				break ;
			else if (flag->output[i] != ' ')
				flag->output[--i] = '+';
		}
	}
	if (flag->hash == 1)
	{
		flag->output[0] = '0';
		if (spc->x == 1)
			flag->output[1] = "x";
		else if (spc->upperx == 1)
			flag->output[1] = "X";
	}
}
