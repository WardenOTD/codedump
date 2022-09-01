/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:25 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/01 11:48:55 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	t_list	*count;
	int	i;

	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			//calls function...?
			//returns i??
			//i += returned i????
			//continue ;??????
		}
		ft_putchar_fd(str[i], 1);
		ft_lstadd_back(&count, ft_lstnew("+1"));
		i++;
	}
	return (ft_lstsize(count));
}

int	minimum_width(const char *str, int i, va_list list, t_list *count)
{
	int		zero;
	int		width;
	char	*output;

	zero = 0;
	width = 0;
	if (str[++i] == '0')
	{
		zero = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		width = str[i++] - 48;
		width *= 10;
	}
	width /= 10;
	output = (char *)malloc(sizeof(char) * (width + 1));
	if (!output)
		return (0);
	output[width] = 0;
	if (zero == 1)
		fillzero(&output);
	if (str[i] == '.')
		i = precision(i, str, &output);
	if ( 0)
		return (0);
	return (i);
}

void	fillzero(char **output)
{
	int	i;

	i = 0;
	while (*output[i])
		*output[i++] = 48;
}

int	precision(int i, const char *str, char **output)
{
	int	width;
	int	l;

	width = 0;
	l = 0;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		width = str[i++] - 48;
		width *= 10;
	}
	width /= 10;
	while (*output[l])
		l++;
	while (width-- > 0)
		*output[l--] = 0;
	return (i);
}

int	rolecall(const char *str, int i, va_list list, t_list *count, char *output)
{
	if (str[i] == 'c')
		return (get_char(list));
	if (str[i] == 's')
		return (get_str(list));
	if (str[i] == 'p')
		return (get_ptr(list));
	if (str[i] == 'd' || str[i] == 'i')
		return (get_deci_int(list));
	if (str[i] == 'u')
		return (get_unsigned(list));
	if (str[i] == 'x')
		return (get_hex_lower(list));
	if (str[i] == 'X')
		return (get_hex_upper(list));
	if (str[i] == '%')

	return (0);
}
