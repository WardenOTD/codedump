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

char	*ft_getline(char *string)
{
	int		i;
	int		j;
	char	*line;
	int		m;

	m = 0;
	i = checkcount(string, '\n');
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
	line[++m] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!string)
		string = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	string = readfile(fd, string);
}
