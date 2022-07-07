/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:08:14 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/07 14:18:47 by jteoh            ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if (!s3)
		return (0);
	i = 0;
	j = 0;
	while ((char)s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while ((char)s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
