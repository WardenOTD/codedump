/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:25 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/09 14:51:21 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	t_flags		flag;
	t_specifier	spc;
	va_list		list;

	flag.printed = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			default_flag(&flag);
			default_specifier(&spc);
			if (!out(&spc, &flag, list, str))
				return (0);
			print(&flag);
			str += flag.extract_size;
			continue ;
		}
		str += percent(&str);
		ft_putchar_fd(*str, 1);
		flag.printed += 1;
		str++;
	}
	va_end(list);
	return (flag.printed);
}

int	percent(const char **str)
{
	if (**str == '%' && **(str + 1) == '%')
		return (1);
	return (0);
}

void	print(t_flags *flag)
{
	flag->printed += ft_strlen(flag->output);
	ft_putstr_fd(flag->output, 1);
	if (flag->output)
		free(flag->output);
	if (flag->extract)
		free(flag->extract);
}

void	default_flag(t_flags *flag)
{
	flag->neg = 0;
	flag->pos = 0;
	flag->hash = 0;
	flag->extract_size = 0;
	flag->extract = NULL;
	flag->output = NULL;
}

void	default_specifier(t_specifier *spc)
{
	spc->c = 0;
	spc->s = 0;
	spc->p = 0;
	spc->di = 0;
	spc->u = 0;
	spc->x = 0;
	spc->upperx = 0;
	spc->hash = 0;
}
