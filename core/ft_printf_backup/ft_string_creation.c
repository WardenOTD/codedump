/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:14:30 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/03 14:38:45 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_set(char *format, t_flags *flag, va_list list)
{
	int	i;

	i = 0;
	while (!ft_isdigit(*format))
		format++;
	if (!allocate_string(format, flag))
		return (0);
	if (flag->space == 1)
	{
		while (format[i] == ' ')
			i++;
		if (!create_space(&format[i], flag))
			return (0);
	}
	if (flag->zero == 1 && flag->space == 0)
	{
		while (format[i] != '0')
			i++;
		if (!create_zero(&format[i], flag))
			return (0);
	}
}

int	allocate_string(char *format, t_flags *flag)
{
	int	l;

	l = 0;
	while (ft_isdigit(*format))
	{
		l = l * 10 + *format - 48;
		format++;
	}
	flag->output = (char *)ft_calloc((l + 1), sizeof(char));
	if (!flag->output)
		return (0);
	flag->output = ft_memset(flag->output, '_', l - 1);
	return (1);
}

int	create_space(char *format, t_flags *flag)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (!ft_isdigit(*format))
	{
		flag->output[0] = ' ';
		return (1);
	}
	while (ft_isdigit(*format))
	{
		if (*format == '0')
		{
			flag->output[0] = ' ';
			return (create_zero(format, flag));
		}
		l = l * 10 + *format - 48;
		format++;
	}
	while (i < l)
		flag->output[i++] = ' ';
	return (1);
}

int	create_zero(char *format, t_flags *flag)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	if (!ft_isdigit(*(++format)))
	{
		while (flag->output[i] != '_')
			i++;
		flag->output[i] = '0';
		return (1);
	}
	while (ft_isdigit(*format))
	{
		l = l * 10 + *format - 48;
		format++;
	}
	if (flag->space == 1)
	{
		i++;
		l++;
	}
	while (i < l)
		flag->output[i++] = '0';
	return (1);
}
