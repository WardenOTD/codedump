/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:18 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/04 10:52:24 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	setarr(char **arr, int fd)
{
	char	*buff;
	int		m;
	int		i;

	m = 1;
	i = 0;
	while (check(arr[i], '\n'))
	{
		if (i != 0)
			i++;
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (0);
		m = read(fd, buff, BUFFER_SIZE);
		if (m == -1)
			return (0);
		if (!scuffedrealloc(arr, i))
			return (0);
		arr[i] = ft_strdup(arr[i], buff);
		if (!arr[i])
			return (freeall(arr));
		free(buff);
	}
	return (1);
}

int	thelinepartofgnl(char **arr, char *line)
{
	int	i;
	int	j;
	int	m;
	int	n;

	m = 0;
	n = 0;
	i = ft_strlen(arr[0]);
	i--;
	if (!linep1(i, m, n, arr, line))
		return (0);
	if (!linep2(i, m, n, arr, line))
		return (0);
	return (1);
}

int	linep1(int i, int m, int n, char **arr, char *line)
{
	int	j;

	if (!check(arr[i--], '\n'))
	{
		while (i > 0 && check(arr[i], '\n'))
			i--;
		j = ft_strlen(arr[i]);
		while (arr[i][j--] != '\n')
			m++;
		i++;
		j++;
		while (arr[i][n++] != '\n')
			m++;
		line = (char *)malloc(sizeof(char) * (m + 2));
		if (!line)
			return (0);
		while (arr[i][++j])
			*line++ = arr[i][j];
		i++;
		while (*arr[i] != '\n')
			*line++ = *arr[i]++;
		*line++ = *arr[i];
		*line = 0;
	}
	return (1);
}

int	linep2(int i, int m, int n, char **arr, char *line)
{
	int	j;

	if (check(arr[i], '\n'))
	{
		while (i > 0 && check(arr[i], '\n'))
			i--;
		j = ft_strlen(arr[i]);
		while (arr[i][j--] != '\n')
			m++;
		i++;
		j++;
		while (arr[i][n++] != 0)
			m++;
		line = (char *)malloc(sizeof(char) * (m + 1));
		if (!line)
			return (0);
		while (arr[i][++j])
			*line++ = arr[i][j];
		i++;
		while (*arr[i] != 0)
			*line++ = *arr[i]++;
		*line = 0;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	**arr;

	if (!arr)
	{
		arr = (char **)malloc(sizeof(char *) * 1);
		if (!arr)
			return (NULL);
		arr[0] = NULL;
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!setarr(arr, fd))
		return (NULL);
	if (!thelinepartofgnl(arr, line))
		return (NULL);
	return (line);
}
