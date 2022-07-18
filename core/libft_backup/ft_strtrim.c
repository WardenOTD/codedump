/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:21:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/18 11:44:50 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcheck(char *str, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == *str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1c;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = ft_strlen((char *)s1);
	while ((char)s1[i] && ft_setcheck((char *)&s1[i], (char *)set))
		i++;
	while (j > i && ft_setcheck((char *)&s1[j - 1], (char *)set))
		j--;
	s1c = (char *)malloc(ft_strlen((char *)s1) * (j - i + 1));
	if (!s1c)
		return (0);
	n = 0;
	while (i < j)
		s1c[n++] = (char)s1[i++];
	s1c[n] = '\0';
	return (s1c);
}
