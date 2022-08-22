/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:18 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/18 16:58:45 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	readfd(int fd, char **string)
{
	int		rv;
	char	*buff;

	rv = 1;
	while (rv)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (-42);
		rv = read(fd, buff, BUFFER_SIZE);
		if (rv == -1)
			return (-42);
		*string = ft_strjoin(*string, buff);
		if (!string)
			return (-42);
		if (check(buff, '\n'))
		{
			free(buff);
			return (rv);
		}
		free(buff);
	}
	return (rv);
}

char	*readstring(char *string)
{
	char	*tmp;
	int		i;
	int		j;

	j = 1;
	i = ft_strlen(string);
	while (string[i--] != '\n')
		continue ;
	while (string[i--] != '\n')
		j++;
	tmp = (char *)malloc(sizeof(char) * (j + 2));
	if (!tmp)
		return (NULL);
	j = 0;
	i += 2;
	while (string[i] != '\n')
		tmp[j++] = string[i++];
	tmp[j++] = string[i];
	tmp[j] = 0;
	return (tmp);
}

char	*readeof(char *string)
{
	char	*tmp;
	int		i;
	int		j;

	j = 1;
	i = ft_strlen(string);
	while (string[i--] != '\n')
		j++;
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	i += 2;
	while (string[i] != 0)
		tmp[j++] = string[i++];
	tmp[j] = 0;
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;
	int			rv;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!string)
	{
		string = (char *)malloc(sizeof(char) * 1);
		if (!string)
			return (NULL);
		string[0] = 0;
	}
	rv = readfd(fd, &string);
	if (rv == -42)
		return (NULL);
	if (!string)
		return (NULL);
	if (rv != 0)
		line = readstring(string);
	if (rv == 0)
		line = readeof(string);
	if (!line)
		return (NULL);
	return (line);
}
