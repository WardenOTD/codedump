/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:46 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/04 10:58:17 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

char	*ft_strdup(char *dest, const char *s1)
{
	int		i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (0);
	i = 0;
	while ((char)s1[i] != '\0')
	{
		dest[i] = (char)s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check(char *string, int c)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == (char)c)
			return (0);
	}
	return (1);
}

int	freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	return (0);
}

int	scuffedrealloc(char **arr, int i)
{
	char	**tmp;
	int		j;

	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!tmp)
		return (0);
	tmp[i + 2] = NULL;
	while (arr[j])
	{
		tmp[j] = ft_strdup(tmp[j], arr[j]);
		j++;
	}
	freeall(arr);
	arr = (char **)malloc(sizeof(char *) * (i + 2));
	if (!arr)
		return (0);
	arr[i + 2] = NULL;
	while (j-- != 0)
		arr[j] = ft_strdup(arr[j], tmp[j]);
	freeall(tmp);
	return (1);
}
