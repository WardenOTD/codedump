/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:33:48 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/09 13:59:23 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	findspc(const char *str, t_specifier *spc)
{
	int	i;

	i = 0;
	while (!ft_isalpha(str[i]) && str[i])
		i++;
	return (findspc1(str[i], i, spc));
}

int	findspc1(int str, int i, t_specifier *spc)
{
	if (str == 'c')
		spc->c = 1;
	else if (str == 's')
		spc->s = 1;
	else
		return (findspc2(str, i, spc));
	return (++i);
}

int	findspc2(int str, int i, t_specifier *spc)
{
	if (str == 'p')
		spc->p = 1;
	else if (str == 'd' || str == 'i')
		spc->di = 1;
	else
		return (findspc3(str, i, spc));
	return (++i);
}

int	findspc3(int str, int i, t_specifier *spc)
{
	if (str == 'u')
		spc->u = 1;
	else if (str == 'x')
		spc->x = 1;
	else
		return (findspc4(str, i, spc));
	return (++i);
}

int	findspc4(int str, int i, t_specifier *spc)
{
	if (str == 'X')
		spc->upperx = 1;
	else if (str == '%')
		spc->hash = 1;
	else
		return (0);
	return (++i);
}
