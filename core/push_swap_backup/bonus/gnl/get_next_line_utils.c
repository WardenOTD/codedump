/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:46 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 14:43:22 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *s)
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

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!*s1 && !*s2)
	{
		free(s1);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char)
			* (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

int	check(char *string, int c)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == (char)c)
			return (1);
	}
	return (0);
}

char	*gnl_strdup(const char *s1)
{
	char	*s1c;
	int		i;

	s1c = (char *)malloc(gnl_strlen((char *)s1) + 1);
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
