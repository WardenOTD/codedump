/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:49:35 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/01 16:07:25 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_char(t_flags *flag, va_list list)
{
	char	c;
	int		i;

	c = (char)va_arg(list, int);
	if (flag->neg)
		flag->output[0] = c;
	i = ft_strlen(flag->output);
	if (!flag->neg)
		flag->output[--i] = c;
	return (1);
}
