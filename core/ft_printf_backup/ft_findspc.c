/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:33:48 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/09 13:02:15 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	findspc(const char *str, t_specifier *spc)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		if (str[i] == 'c')
		{
			spc->c = 1;
			break ;
		}
		else if (str[i] == 's')
		{
			spc->s = 1;
			break ;
		}
		i++;
	}
	if (str[i] == 0)
		return (findspc2(str, spc));
	return (++i);
}

int	findspc2(const char *str, t_specifier *spc)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		if (str[i] == 'p')
		{
			spc->p = 1;
			break ;
		}
		else if (str[i] == 'd' || str[i] == 'i')
		{
			spc->di = 1;
			break ;
		}
		i++;
	}
	if (str[i] == 0)
		return (findspc3(str, spc));
	return (++i);
}

int	findspc3(const char *str, t_specifier *spc)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		if (str[i] == 'u')
		{
			spc->u = 1;
			break ;
		}
		else if (str[i] == 'x')
		{
			spc->x = 1;
			break ;
		}
		i++;
	}
	if (str[i] == 0)
		return (findspc4(str, spc));
	return (++i);
}

int	findspc4(const char *str, t_specifier *spc)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		if (str[i] == 'X')
		{
			spc->upperx = 1;
			break ;
		}
		else if (str[i] == '%')
		{
			spc->hash = 1;
			break ;
		}
		i++;
	}
	if (str[i] == 0)
		return (0);
	return (++i);
}
