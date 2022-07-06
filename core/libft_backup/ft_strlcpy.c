/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:57:36 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/06 11:32:57 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)src);
	i = 0;
	if (dstsize == 0)
		return (len);
	while (i < dstsize - 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (*src == '\0' || i == dstsize - 1)
	{
		*dst = '\0';
	}
	return (len);
}
