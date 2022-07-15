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

static int	charcount(char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

static int	limitedcount(char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c || *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static char	*copy(char **arr, int i, char *s, char c)
{
	if (*(s + 1) == c)
	{
		*arr[i] = '\0';
		return (*arr);
	}
	s++;
	while (*s != c)
	{
		*arr[i] = *s;
		s++;
		i++;
	}
	return (*arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(s) * charcount((char *)s, c) + 1);
	if (!arr)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		if ((char)*s == c)
		{
			arr[i] = (char *)malloc(sizeof(s) * limitedcount((char *)s, c) + 1);
			if (!arr[i])
				return (0);
			arr[i] = copy(arr, i, (char *)s, c);
			i++;
		}
		s++;
	}
	return (arr);
}

#include <stdio.h>
int	main()
{
	char	**arr;
	char	str[] = "alorem aipsum adorem aliptum as aa";
	char	sep = 'a';
	arr = ft_split(str, sep);
	int	i;
	i = 0;
	while (arr[i] != '\0')
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
