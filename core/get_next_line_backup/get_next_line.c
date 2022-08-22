/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:18 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/22 11:37:53 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfd(int fd, char *string)
{
	int		rv;
	char	*buff;

	rv = 1;
	while (rv)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		rv = read(fd, buff, BUFFER_SIZE);
		if (rv == -1)
			return (NULL);
		buff[rv] = 0;
		string = ft_strjoin(string, buff);
		if (!string)
			return (NULL);
		if (check(buff, '\n'))
		{
			free(buff);
			return (string);
		}
		free(buff);
	}
	return (string);
}

char	*readstring(char *string)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\n')
		tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (string[i] == '\0')
		tmp = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
		tmp[j++] = string[i++];
	if (string[i] == '\n')
		tmp[j++] = string[i];
	tmp[j] = 0;
	return (tmp);
}

char	*trim(char *string)
{
	char	*tmp;
	int		i;
	int		j;

	j = ft_strlen(string);
	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!tmp)
		return (0);
	if (string[i] == '\n')
		++i;
	j = 0;
	while (string[i] != '\0')
		tmp[j++] = string[i++];
	tmp[j] = 0;
	free(string);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!string)
	{
		string = malloc(sizeof(char) * 1);
		string[0] = 0;
	}
	string = readfd(fd, string);
	if (!string)
		return (NULL);
	line = readstring(string);
	if (!line)
		return (NULL);
	string = trim(string);
	if (!string)
		return (NULL);
	return (line);
}
