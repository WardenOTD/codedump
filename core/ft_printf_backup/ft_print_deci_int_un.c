/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci_int_un.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:45:12 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 17:15:37 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_deci_int(int i, va_list list, t_list *count)
{
	int	num;
	int	length;
	int	printed;

	num = va_arg(list, int);
	printed = num;
	while (printed > 0)
	{
		printed /= 10;
		length++;
	}
	while (printed++ < length)
		ft_lstadd_back(&count, ft_lstnew("+1"));
	ft_putnbr_fd(num, 1);
	return (++i);
}

int	print_unsigned(int i, va_list list, t_list *count)
{
	unsigned int	uni;
	unsigned int	tmp;
	int				l;
	char			*arr;

	uni = va_arg(list, unsigned int);
	tmp = uni;
	l = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		l++;
	}
	arr = (char *)malloc(sizeof(char) * (l + 1));
	if (!arr)
		return (0);
	arr[l--] = 0;
	unsigned_helper(&arr, uni, tmp, l);
	l = ft_strlen(arr);
	while (uni++ < l)
		ft_lstadd_back(&count, ft_lstnew("+1"));
	ft_putstr_fd(arr, 1);
	return (++i);
}

void	unsigned_helper(char **arr, unsigned int uni, unsigned int tmp, int l)
{
	while (uni >= 0)
	{
		tmp = uni % 10;
		uni /= 10;
		*arr[l--] = tmp + 48;
	}
}
