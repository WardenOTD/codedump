/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:51:12 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/06 17:38:49 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(dest + i) = *(source + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	}
	return (dst);
}
