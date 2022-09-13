/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:14:30 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/13 13:40:41 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_set(char *format, t_flags *flag, t_specifier *spc, va_list list)
{
	int	i;

	while (!ft_isdigit(*format))
		format++;
	if (!allocate_string(format, flag))
		return (0);
	if (flag->space == 1)
	{
		i = 0;
		while (format[i] == ' ')
			i++;
		create_space(&format[i], flag);
	}
	if (flag->zero == 1 && flag->space == 0)
	{
		i = 0;
		while (format[i] != '0')
			i++;
		create_zero(&format[i], flag);
	}
	if (flag->precision == 1 && spc->s != 1)
	{
		i = 0;
		while (format[i] != '.')
			i++;
		create_precision_not_string(&format[i], flag);
	}
	if (flag->precision == 1 && spc->s == 1)
	{
		i = 0;
		while (format[i] != '.')
			i++;
		create_precision_with_string(&format[i], flag);
	}
	if (flag->neg == 1)
	{
		i = 0;
		while (format[i] != '-')
			i++;
		create_nega_space(&format[i], flag);
	}
	if (flag->hash == 1)
		create_hash(flag);
	if (flag->pos == 1)
		create_posi(flag);
	return (1);
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

void	minimum_width(char *format, t_flags *flag)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (!ft_isdigit(*format))
		format++;
	while (ft_isdigit(*format))
	{
		l = l * 10 + *format - 48;
		format++;
	}
	while (i < l)
		flag->output[i++] = ' ';
}

void	create_space(char *format, t_flags *flag)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (!ft_isdigit(*format))
	{
		flag->output[0] = ' ';
		return ;
	}
	if (flag->zero == 1)
	{
		flag->output[0] == ' ';
		return (create_zero(format, flag));
	}
	while (ft_isdigit(*format))
	{
		l = l * 10 + *format - 48;
		format++;
	}
	while (i < l)
		flag->output[i++] = ' ';
}

void	create_zero(char *format, t_flags *flag)
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
		return ;
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
}

void	create_precision_not_string(char *format, t_flags *flag)
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
		return ;
	}
	while (ft_isdigit(*format))
	{
		l = l * 10 + *format - 48;
		format++;
	}
	while (i < l)
		flag->output[i++] = '0';
}

void	create_precision_with_string(char *format, t_flags *flag)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	if (!ft_isdigit(*(++format)))
	{
		while (flag->output[i] != '_')
			i++;
		flag->output[i] = 's';
		return ;
	}
	while (ft_isdigit(*format))
	{
		l = l * 10 + *format - 48;
		format++;
	}
	while (i < l)
		flag->output[i++] = 's';
}

void	create_nega_space(char *format, t_flags *flag)
{
	int	l;

	l = 0;
	if (!ft_isdigit(*(++format)))
	{
		while (flag->output[l] != 0)
			l++;
		flag->output[--l] = ' ';
		return ;
	}
	while (ft_isdigit(*format))
	{
		l = l * 10 + *format - 48;
		format++;
	}
	while (l > 0)
		flag->output[--l] = ' ';
}

void	create_posi(t_flags *flag)
{
	flag->output[0] = '+';
}

void	create_hash(t_flags *flag)
{
	t_specifier	*spc;

	flag->output[0] = '0';
	if (spc->x == 1)
		flag->output[1] = 'x';
	if (spc->upperx == 1)
		flag->output[1] = 'X';
}
