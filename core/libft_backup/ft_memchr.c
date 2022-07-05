/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:08:53 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/05 16:21:37 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)s;
	while (*temp != '\0' && i != n)
	{
		if (*temp == c)
		{
			return ((void *)s);
		}
		else
		{
			i++;
			temp++;
			s++;
		}
	}
	return (0);
}
