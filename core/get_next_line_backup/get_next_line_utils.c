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

size_t	ft_strlen(const char *s)
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
	s1c[i] = '\0';
	return (s1c);
}

char	**readfile(int fd, char **arr)
{
	int		m;
	char	*buff;
	int		i;

	i = 0;
	m = 1;
	while (ccheck(arr[i++], '\n', arr, 0) == 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		m = read(fd, buff, BUFFER_SIZE);
		if (m == -1)
			return (NULL);
		arr = arrset(arr);
		if (!arr)
			return (NULL);
		arr[i] = ft_strdup(buff);
		free(buff);
	}
	return (arr);
}

int	ccheck(char *string, int c, char **arr, int type)
{
	int	i;

	i = 0;
	if (type == 0)
	{
		while (string[i])
		{
			if (string[i] == (char)c)
				return (1);
			i++;
		}
	}
	if (type == 1)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	return (0);
}

char	*glhelper(char **arr, int i, int j, char *line, int m)
{
	if (ccheck(arr[--i], '\n', arr, 0) == 1)
	{
		while (ccheck(arr[--i], '\n', arr, 0) == 0)
			continue ;
		while (arr[i][j] != '\n')
			j++;
		while (arr[i][++j] != '\n' || arr[i][j] != '\0')
		{
			line[m++] = arr[i][j];
			if (arr[i][j + 1] == '\0')
			{
				i++;
				j = 0;
			}
		}
		line[m++] = arr[i][j];
		line[m] = '\0';
	}
	else if (ccheck(arr[--i], '\n', arr, 0) == 0)
	{
		while (ccheck(arr[--i], '\n', arr, 0) == 0)
			continue ;
		while (arr[i][j] != '\n')
			j++;
		while (arr[i][++j] != '\0')
			line [m++] = arr[i][j];
		line[m] = '\0';
	}
	return (line);
}
