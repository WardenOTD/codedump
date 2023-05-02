/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:08 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/02 17:49:37 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validity_helper(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j] != '\n')
	{
		if (data->map[i][j] == 0)
			return (0);
		j++;
	}
	return (--j);
}

int	validity(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = validity_helper(data, i);
	if (j == 0)
		return (0);
	while (data->map[i] != NULL)
	{
		if (data->map[i][0] == '0' || data->map[i][j] == '0')
			return (0);
		i++;
	}
	j = validity_helper(data, --i);
	if (j == 0)
		return (0);
	return (1);
}

int	parse(t_data *data, char *argv)
{
	int		fd;
	int		i;

	data->map = (char **)malloc(sizeof(char **) * (data->mapsize + 1));
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
	tmp = (char **)malloc(sizeof(char **) * (i + 1));
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
	free(tmp);
	if (data->ccount == 0 && data->exit == 0)
		return (1);
	return (0);
}

void	broke(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
		free(data->map[i++]);
	free(data->map);
	printf("failed w/ free\n");
	exit(1);
}

void	init(t_data *data)
{
	data->sprite_x = 0;
	data->sprite_y = 0;
	data->sprite_x60 = 0;
	data->sprite_y60 = 0;
	data->mapsize = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->ccount = 0;
	data->exit = 1;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	if (argc != 2)
		return (0);
	if (mapsize(&data, argv[1]) == 0)
		return (printf("map parse failed\n"));
	if (parse(&data, argv[1]) == 0)
		broke(&data);
	if (ccount(&data) == 0 || pecount(&data) == 0)
		return (printf("Count failed\n"));
	if (flood(&data) == 0)
		return (printf("FLODFUCK: invalid map\n"));
	if (mlx(&data) == 0)
		return (0);
	return (0);
}

/*
gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3 so_long.c mlx_stuff.c mlx_movement_admin.c put_to_term.c get_next_line.c get_next_line_utils.c -o so_long && rm -rf *.dSYM

./so_long ./maps/map1.ber
./so_long ./maps/map2.ber

*/
