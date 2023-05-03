/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:18:22 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/03 19:19:32 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(t_data *data, char *argv)
{
	int		fd;
	int		i;

	data->map = (char **)malloc(sizeof(char *) * (data->mapsize + 1));
	fd = open(argv, O_RDONLY | O_EXCL);
	i = 0;
	while (data->mapsize > 0)
	{
		data->map[i] = get_next_line(fd);
		i++;
		data->mapsize--;
	}
	data->map[i] = NULL;
	if (close(fd) < 0)
		return (0);
	if (validity(data) == 0)
		return (0);
	return (1);
}

int	mapsize(t_data *data, char *argv)
{
	int		fd;
	char	*tmp;

	data->mapsize = 0;
	tmp = malloc(sizeof(char) * 1);
	tmp[0] = 'a';
	fd = open(argv, O_RDONLY | O_EXCL);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		data->mapsize++;
	}
	if (data->mapsize <= 1)
		return (0);
	free(tmp);
	if (close(fd) < 0)
		return (0);
	return (1);
}

int	ccount(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'C')
				data->ccount++;
			j++;
		}
		i++;
	}
	if (data->ccount == 0)
		return (0);
	return (1);
}

int	pecount(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'P' || data->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}
