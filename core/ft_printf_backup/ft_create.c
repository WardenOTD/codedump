/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:13:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/13 12:43:40 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out(t_specifier *spc, t_flags *flag, va_list list, const char *str)
{
	char	*cc;

	if (!findspc(str, spc))
		return (0);
	if (spc->x == 1 || spc->upperx == 1 || spc->p == 1)
		return (if_hex(flag, spc, list));
	if (spc->c == 1)
		return (if_char(flag, list));
	if (spc->di == 1 || spc->u == 1)
		return (if_int(spc, flag, list));
	cc = create_c(spc, list);
	if (!cc)
		return (0);
	write_to_fd(cc, flag, 1);
	free_check(cc);
	return (1);
}

char	*create_c(t_specifier *spc, va_list list)
{
	char	*cc;

	if (spc->s == 1)
	{
		cc = va_arg(list, char *);
		if (!cc)
		{
			free(cc);
			cc = ft_strdup("(null)");
			if (!cc)
				return (0);
		}
		return (cc);
	}
	return (0);
}

void	free_check(char *cc)
{
	if (!ft_strncmp(cc, "(null)", 6))
		free(cc);
}

void	write_to_fd(char *str, t_flags *flag, int fd)
{
	flag->printed += ft_strlen(str);
	ft_putstr_fd(str, fd);
}
