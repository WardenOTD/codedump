/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:15:29 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/07 13:24:09 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s1c;
	int		i;

	s1c = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!s1c)
		return (0);
	i = 0;
	while ((char)s1[i] != '\0')
	{
		s1c[i] = (char)s1[i];
		i++;
	}
	return (s1c);
}
