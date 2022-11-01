/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/11/01 11:46:03 by jteoh            ###   ########.fr       */
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
	flag->extract[i] = 0;
	while (i-- > 0)
		*flag->extract++ = *str++;
}

int	findspc(const char *str, t_specifier *spc)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == 'c')
			spc->c = 1;
		else if (str[i] == 's')
			spc->s = 1;
		else if (str[i] == 'p')
			spc->p = 1;
		else if (str[i] == 'd' || str[i] == 'i')
			spc->di = 1;
		else if (str[i] == 'u')
			spc->u = 1;
		else if (str[i] == 'x')
			spc->x = 1;
		else if (str[i] == 'X')
			spc->upperx = 1;
		else if (str[i] == '%')
			spc->hash = 1;
		i++;
	}
	if (str[i] == 0)
		return (0);
	return (++i);
}
