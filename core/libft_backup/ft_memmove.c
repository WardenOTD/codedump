/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:51:12 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/05 15:13:42 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*source;
	size_t	temp[500];

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	while (i != len)
	{
		temp[i] = *source;
		i++;
		source++;
	}
	i = 0;
	while (i != len)
	{
		*dest = temp[i];
		i++;
		dest++;
	}
	return (dst);
}
