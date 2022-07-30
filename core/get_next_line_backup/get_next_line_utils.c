/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:46 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/30 10:16:11 by jteoh            ###   ########.fr       */
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

char	*readfile(int fd, char *string, int count)
{
	int		m;
	char	*buff;
	int		n;

	n = 0;
	buff = NULL;
	m = 1;
	while (n <= count)
	{
		m = read(fd, buff, BUFFER_SIZE);
		if (m == -1)
			return (NULL);
		string = ft_strjoin(string, buff);
		free(buff);
		n += ccheck(string, '\n');
	}
	count++;
	if (m == 0)
		count = -1;
	return (string);
}

int	ccheck(char *string, int c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	checkcount(char *string, int c, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < count && string[i])
	{
		if (string[i] == (char)c)
			j++;
		i++;
	}
	return (i);
}
