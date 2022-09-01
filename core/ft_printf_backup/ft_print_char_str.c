/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:29:50 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/01 11:10:14 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_char(va_list list)
{
	char	c;

	c = va_arg(list, char);
	return (c);
}

char	*get_str(va_list list)
{
	char	*str;

	*str = va_arg(list, char *);
	return (str);
}
