/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:28:06 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/19 10:02:02 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ss = (char *)malloc(len + 1);
	if (!ss || !s)
		return (0);
	while ((char)s[i] != '\0')
	{
		if (i == (int)start)
		{
			while (j < (int)len)
			{
				ss[j] = (char)s[i + j];
				j++;
			}
			ss[j] = '\0';
			return (ss);
		}
		i++;
	}
	return (ss);
}
