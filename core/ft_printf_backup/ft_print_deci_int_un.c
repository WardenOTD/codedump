/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci_int_un.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:45:12 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/01 11:50:37 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_deci_int(va_list list)
{
	int		num;
	char	*asnum;

	num = va_arg(list, int);
	asnum = ft_itoa(num);
	if (!asnum)
		return (0);
	return (asnum);
}

char	*get_unsigned(va_list list)
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
	return (arr);
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

int	print_deci_int(va_list list, t_list *count, char *output)
{
	char	*deci_int;
	int		i;
	int		j;

	deci_int = get_deci_int(list);
	if (!deci_int)
		return (0);
	i = ft_strlen(deci_int);
	j = ft_strlen(output);
	if (i >= j)
	{
		ft_putstr_fd(deci_int, 1);
		while (i-- > 0)
			ft_lstadd_back(&count, ft_lstnew("+1"));
		return (1);
	}
	if (i < j)
	{
		while (i > 0)
			output[j--] = deci_int[i--];
		ft_putstr_fd(output, 1);
		j = ft_strlen(output);
		while (j-- > 0)
			ft_lstadd_back(&count, ft_lstnew("+1"));
		return (1);
	}
	return (0);
}

int	print_un(va_list list, t_list *count, char *output)
{
	char	*un;
	int		i;
	int		j;

	un = get_unsigned(list);
	if (!un)
		return (0);
	i = ft_strlen(un);
	j = ft_strlen(output);
	if (i >= j)
	{
		ft_putstr_fd(un, 1);
		while (i-- > 0)
			ft_lstadd_back(&count, ft_lstnew("+1"));
		return (1);
	}
	if (i < j)
	{
		while (i > 0)
			output[j--] = un[i--];
		ft_putstr_fd(output, 1);
		j = ft_strlen(output);
		while (j-- > 0)
			ft_lstadd_back(&count, ft_lstnew("+1"));
		return (1);
	}
	return (0);
}
