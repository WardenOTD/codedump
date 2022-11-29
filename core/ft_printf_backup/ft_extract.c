/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/11/29 12:42:35 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cnc(const char *str, t_specifier *spc, t_flags *flag)
{
	int	i;

	i = 0;
	i = findspc(str, spc);
	if (i == 0)
		return (0);
	flag->extract = (char *)malloc((sizeof(char) * (i + 1)));
	if (!(flag->extract))
		return (0);
	flag->extract[i] = 0;
	while (i-- > 0)
		*flag->extract++ = *str++;
	return (1);
}

int	findspc(const char *str, t_specifier *spc)
{
	int	i;

	i = 0;
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

	i = 0;
	while (str[i] != 0)
	{
		else if (str[i] == 'p')
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

	i = 0;
	while (str[i] != 0)
	{
		else if (str[i] == 'u')
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

	i = 0;
	while (str[i] != 0)
	{
		else if (str[i] == 'X')
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
