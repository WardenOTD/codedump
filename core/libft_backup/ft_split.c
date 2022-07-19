/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:01:06 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/19 15:35:57 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charcount(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		if ((s[j] != c && s[j + 1] == c) || s[j + 1] == '\0')
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
	while (s[j] != c && s[j] != '\0')
	{
		j++;
		i++;
	}
	return (i);
}

static void	copyover(char *dest, char *src, int amt)
{
	int	i;

	i = 0;
	while (i < amt)
	{
		dest[i] = src[i];
		i++;
	}
}

static int	copy(char **arr, char *str, char c, int count)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (m <= count && str[i] != 0)
	{
		if (str[i] == c)
			i++;
		else
		{
			arr[m] = (char *)ft_calloc(sizeof(char),
					(limitedcount(str + i, c) + 1));
			if (!arr[m])
			{
				while (m > 0)
					free(arr[--m]);
				return (0);
			}
			copyover(arr[m], str + i, limitedcount(str + i, c));
			i += limitedcount(str + i, c);
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

	if (!s)
		return (0);
	str = (char *)s;
	count = charcount(str, c);
	arr = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!arr)
		return (0);
	arr[count] = 0;
	if (copy(arr, str, c, count) == 0)
	{
		free(arr);
		return (0);
	}
	return (arr);
}
