/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:18 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/30 10:17:03 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *string, int count)
{
	int		i;
	int		j;
	char	*line;
	int		m;

	m = 0;
	i = checkcount(string, '\n', count);
	j = i;
	while (string[j] != '\n' || string[j] != '\0')
		j++;
	if (string[i] != '\0')
		line = (char *)malloc(sizeof(char) * (j + 2));
	if (string[i] == '\0')
		line = (char *)malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	while (i < j)
	{
		line[m++] = string[i++];
		if (string[j] == string[i] && string[j] == '\n')
			line[m] = string[j];
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*string;
	static int	count = 0;

	string = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = readfile(fd, string, count);
	if (!string)
		return (NULL);
	if (count == -1)
		return (NULL);
	line = ft_getline(string, count);
	if (!line)
		return (NULL);
	return (line);
}
