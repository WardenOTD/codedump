/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:12:19 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/29 10:12:19 by jteoh            ###   ########.fr       */
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
		i++;
		j++;
	}
	retrun (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!s3)
		return (0);
	i = 0;
	j = 0;
	while ((char)s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while ((char)s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_getline(char *string)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (string[i] != '\n' || string[i] != '\0')
		i++;
	if (string[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (string[i] == '\0')
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = *string;
		j++;
		string++;
		if (string[j] == string[i] && string[i] == '\n')
			line[j] = *string;
	}
	string++;
	return (line);
}

char	*readfile(int fd, char *string)
{
	int		m;
	char	*buff;

	m = 1;
	while (m != 0)
	{
		m = read(fd, buff, BUFFER_SIZE);
		if (m == -1)
			return (NULL);
		string = ft_strjoin(string, buff);
		free(buff);
	}
	return (string);
}
