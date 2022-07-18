/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:01:06 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/18 11:38:18 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	charcount(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && s[j + 1] == c)
			i++;
		j++;
	}
	return (i);
}

static int	limitedcount(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j] != c || s[j] != '\0')
	{
		j++;
		i++;
	}
	return (i);
}

static void	copyover(char *dest, char *src, int amt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < amt)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	copy(char **arr, char *str, char c)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			arr[m] = (char *)malloc(sizeof(char)
					* (limitedcount(str + i, c) + 1));
			if (!arr[m])
			{
				while (m > 0)
					free(arr[--m]);
				return (0);
			}
			copyover(arr[m], str + i, limitedcount(str + i, c));
			i++;
			m++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;
	int		count;

	str = (char *)s;
	count = charcount(str, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (0);
	arr[count + 1] = 0;
	if (copy(arr, str, c) == 0)
		return (0);
	return (arr);
}
