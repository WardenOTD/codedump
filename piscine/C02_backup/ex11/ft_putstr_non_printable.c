/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:43:39 by jteoh             #+#    #+#             */
/*   Updated: 2022/05/30 11:01:09 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(char n)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(92);
	if (n >= 16)
		ft_putchar(hex[n / 16]);
	else
		ft_putchar('0');
	ft_putchar(hex[n % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 32)
			ft_print_hex(str[i]);
		else
			ft_putchar(str[i]);
	}
}
