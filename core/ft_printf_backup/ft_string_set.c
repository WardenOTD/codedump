/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:44:28 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/13 14:29:17 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg(t_flags *flag, t_specifier *spc, va_list list)
{
	if (spc->c = 1)
	{
		is_c(flag, spc, list);
	}
	else if (spc->s = 1)
	{

	}
	else if (spc->p = 1)
	{

	}
	else if (spc->di = 1)
	{

	}
	else
		get_arg_2(flag, spc, list)
}

int	get_arg_2(t_flags *flag, t_specifier *spc, va_list list)
{
	if (spc->u = 1)
	{

	}
	else if (spc->x = 1)
	{

	}
	else if (spc->upperx = 1)
	{

	}
}

void	is_c(t_flags *flag, t_specifier *spc, va_list list)
{
	int	i;

	i = 0;
	if (flag->neg == 1)
		flag->output[0] = va_arg(list, char);
	else
	{
		while (flag->output[i])
			i++;
		i--;
		flag->output[i] = va_arg(list, char);
	}
	flag->printed += ft_strlen(flag->output);
	ft_putstr_fd(flag->output, 1);
	default_flag(flag);
	default_specifier(spc);
	free(flag->output);
}

void	is_s(t_flags *flag, t_specifier *spc, va_list list)
{
	char	*str;
	int		i;
	int		l;

	str = va_arg(list, char *);
	i = 0;
	l = 0;
	if (ft_strlen(str) >= ft_strlen(flag->output))
	{
		ft_putstr_fd(str, 1);
		flag->printed += ft_strlen(str);
	}
	else if (flag->precision == 1)
	{
		while (flag->output[i] != 's')
			i++;
		while (flag->output[i] == 's')
			flag->output[i++] = str[l++];
		flag->printed += ft_strlen(flag->output);
		ft_putstr_fd(flag->output, 1);
	}
	else if (flag->precision == 0)
	{
		if (flag->neg == 1)
		{
			while (str[l])
				flag->output[i++] = str[l++];
		}
		else
		{
			while (flag->output[i])
				i++;
			while (str[l])
				l++;
			while (l > 0)
				flag->output[--i] = str[--l];
		}
		flag->printed += ft_strlen(flag->output);
		ft_putstr_fd(flag->output, 1);
	}
	default_flag(flag);
	default_specifier(spc);
	free(flag->output);
	free(str);
}
