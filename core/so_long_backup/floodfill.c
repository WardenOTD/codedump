/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:17:01 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/03 17:16:01 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locatep(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'P')
			{
				data->sprite_x = j;
				data->sprite_y = i;
				data->sprite_x60 = j * 60;
				data->sprite_y60 = i * 60;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**dupe(t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	while (data->map[i] != NULL)
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data->map[i] != NULL)
	{
		tmp[i] = ft_strdup(data->map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int	fill(int x, int y, char **tmp, t_data *data)
{
	int	up;
	int	left;
	int	down;
	int	right;

	if (tmp[y][x] == '1')
		return (1);
	if (tmp[y][x] == '0')
		tmp[y][x] = '1';
	if (tmp[y][x] == 'C')
	{
		data->ccount--;
		tmp[y][x] = '1';
	}
	if (tmp[y][x] == 'E')
	{
		data->exit--;
		tmp[y][x] = '1';
		return (1);
	}
	up = fill(x, y - 1, tmp, data);
	left = fill(x - 1, y, tmp, data);
	down = fill(x, y + 1, tmp, data);
	right = fill(x + 1, y, tmp, data);
	return (1);
}

int	flood(t_data *data)
{
	char	**tmp;

	tmp = dupe(data);
	locatep(data);
	fill(data->sprite_x, data->sprite_y, tmp, data);
	broke(tmp);
	if (data->ccount == 0 && data->exit == 0)
		return (1);
	return (0);
}
