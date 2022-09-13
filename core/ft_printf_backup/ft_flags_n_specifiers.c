/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_n_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:10:28 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/13 13:39:19 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_set(const char *str, int i, t_flags *flag, va_list list)
{
	char		*format;
	t_specifier	*spc;

	format = get_format(str, i, flag);
	specifier_set(format, spc);
	if (!format)
		return (0);
	if (run_tru(format, ' '))
		flag->space = 1;
	if (run_tru0(format, '0'))
		flag->zero = 1;
	if (run_tru(format, '.'))
		flag->precision = 1;
	if (run_tru(format, '-'))
		flag->neg = 1;
	if (run_tru(format, '+'))
		flag->pos = 1;
	if (run_tru(format, '#'))
		flag->hash = 1;
	//function for array creation;;;
	return (ft_strlen(format));
}

int	run_tru(char *format, char c)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i++] == c)
			return (1);
	}
	return (0);
}

int	run_tru0(char *format, char c)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == c && !ft_isdigit(format[i - 1]))
			return (1);
	}
	return (0);
}

char	*get_format(const char *str, int i, t_flags *flag)
{
	char	*format;
	int		l;
	int		j;
	int		er;

	er = 3;
	j = i;
	l = 0;
	while (er != 0)
	{
		er = cmp(str[i++]);
		l++;
		if (er == 2)
			break ;
		if (er == 0)
			return (NULL);
	}
	format = (char *)ft_calloc((l + 1), sizeof(char));
	if (!format)
		return (NULL);
	l = 0;
	while (j < i)
		format[l++] = str[j++];
	return (format);
}

int	cmp(char c)
{
	int		i;
	int		j;
	char	*flag;
	char	*specifier;

	j = 0;
	i = 0;
	flag = "1234567890 -+#.";
	specifier = "cspdiuxX";
	while (flag[i])
	{
		if (flag[i] != c)
			i++;
		if (flag[i] == c)
			return (1);
	}
	while (specifier[j])
	{
		if (specifier[j] != c)
			j++;
		if (specifier[j] == c)
			return (2);
	}
	return (0);
}

void	specifier_set(char *format, t_specifier *spc)
{
	while (*format)
		format++;
	format--;
	if (*format == 'c')
		spc->c = 1;
	else if (*format == 's')
		spc->s = 1;
	else if (*format == 'p')
		spc->p = 1;
	else if (*format == 'd' || *format == 'i')
		spc->di = 1;
	else if (*format == 'u')
		spc->u = 1;
	else if (*format == 'x')
		spc->x = 1;
	else if (*format == 'X')
		spc->upperx = 1;
}
