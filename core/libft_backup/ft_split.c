/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:01:06 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/21 10:47:55 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**setarray(char *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && ((s[i + 1] == c) || s[i + 1] == '\0'))
			j++;
		i++;
	}
	arr = (char **)ft_calloc(j + 1, sizeof(char *));
	if (!arr)
		return (0);
	return (arr);
}

static void	setpointer(char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
			j++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			arr[m] = (char *)ft_calloc(j + 1, sizeof(char));
			if (!arr[m])
			{
				while (arr[m])
					free(arr[--m]);
			}
			m++;
			j = 0;
		}
		i++;
	}
}

static void	copy(char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			arr[m][j] = s[i];
			j++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			m++;
			j = 0;
		}
		i++;
	}
	arr[m] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	arr = setarray(str, c);
	if (!arr)
		return (0);
	setpointer(str, c, arr);
	copy(str, c, arr);
	return (arr);
}
