/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:01:06 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/07 17:26:08 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	charcheck(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			i++;
		j++;
	}
	return (i);
}

static int	recharcheck(char *str, char c)
{
	int	i;

	i = 0;
	while (*str != c && *str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

static void	aloccheck(char *str, int size)
{
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		free(str);
}

static char	*stringcpy(char *arr, char *str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		arr[i] = *str;
		str++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		m;

	m = 0;
	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(s) * charcheck((char *)s, c) + 1);
	if (!arr)
		return (0);
	while ((char)s[j] != '\0')
	{
		if (recharcheck((char *)&s[j], c) > 0)
		{
			aloccheck(&arr[m][i], recharcheck((char *)&s[j], c) + 1);
			arr[m][i] = *stringcpy(&arr[m][i], (char *)&s[j], c);
			m++;
		}
		if (recharcheck((char *)&s[j], c) == 0)
			arr[m][j] = '\0';
		j++;
	}
	return (arr);
}
