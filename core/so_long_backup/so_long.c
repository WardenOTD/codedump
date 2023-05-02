/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:08 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/02 12:26:18 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_ptr;
	void	*floor_ptr;
	void	*sprite_ptr;
	void	*col_ptr;
	void	*exit_ptr;
	int		sprite_x;
	int		sprite_y;
	char	**map;
	int		mapsize;
	int		ccount;
	int		exit;
}				t_data;

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
				data->ccount += 1;
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
	data->exit = 1;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'P')
			{
				data->sprite_x = j;
				data->sprite_y = i;
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

int fill(int x, int y, char **tmp, t_data *data)
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
	printf("up: %d, left: %d, down: %d, right: %d\n", up, left, down, right);
	return (up + left + down + right);
}

int flood(t_data *data)
{
	char	**tmp;
	int		i;

	tmp = dupe(data);
	locatep(data);
	printf("map sprite: %c\n", data->map[data->sprite_y][data->sprite_x]);
	printf("tmp sprite: %c\n", tmp[data->sprite_y][data->sprite_x]);
	i = fill(data->sprite_x, data->sprite_y, tmp, data);
	printf("? %d\n", i);
	if (i == 4 && data->ccount == 0 && data->exit == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	if (mapsize(&data, argv[1]) == 0)
		return (printf("map parse failed\n"));
	if (parse(&data, argv[1]) == 0)
		return (printf("parse failed\n"));
	if (ccount(&data) == 0 || pecount(&data) == 0)
		return (printf("Count failed\n"));
	if (flood(&data) == 0)
		return (printf("FLODFUCK\n"));
	for (int i = 0; data.map[i] != 0; i++)
		printf("%s", data.map[i]);
	return (0);
}

//gcc -Wall -Wextra -Werror -fsanitize=address -g3 so_long.c get_next_line.c get_next_line_utils.c -o so_long && rm -rf *.dSYM
//-lmlx -framework OpenGL -framework AppKit
//./so_long ./maps/map1.ber
