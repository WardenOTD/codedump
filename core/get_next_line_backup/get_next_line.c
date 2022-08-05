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

char	*ft_getline(char **arr, char *line)
{
	int		i;
	int		j;
	int		m;

	i = 0;
	m = 0;
	j = 0;
	while (arr[i] != 0)
		i++;
	if (i--)
	{
		while (ccheck(arr[--i], '\n', arr, 0) == 0)
			continue ;
		while (arr[i][j] != '\n')
			j++;
		j++;
		while (arr[i][j] != '\0' || arr[i][j] != '\n')
		{
			m++;
			j++;
			if (arr[i][j + 1] == '\0')
			{
				i++;
				j = 0;
			}
		}
		line = (char *)malloc(sizeof(char) * (m + 2));
	}
	return (glhelper(arr, ++i, 0, line, 0));
}

void	duplicatearr(char **tmp, char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		tmp[i] = (char *)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1));
		if (!tmp[i])
		{
			while (i-- > 0)
				ccheck("", "", tmp, 1);
			return (NULL);
		}
		tmp[i] = ft_strdup(arr[i]);
		i++;
	}
	tmp[++i] = 0;
}

char	**arrset(char **arr)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!arr)
	{
		tmp = (char **)malloc(sizeof(char *) * 2);
		tmp[1] = 0;
	}
	else
	{
		while (arr[j])
			j++;
		tmp = (char **)malloc(sizeof(char *) * (j + 2));
		if (!tmp)
		{
			ccheck("", "", arr, 1);
			return (NULL);
		}
		duplicatearr(tmp, arr);
		ccheck("", "", arr, 1);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	**arr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	arr = readfile(fd, arr);
	if (!arr)
		return (NULL);
	line = ft_getline(arr, line);
	if (!line)
		return (NULL);
	return (line);
}
