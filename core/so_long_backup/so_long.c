/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:08 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/03 17:17:02 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	broke(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
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

void	main_split(t_data *data, char **argv)
{
	if (mapsize(data, argv[1]) == 0)
	{
		ft_putstr_fd("Read map failed\n", 1);
		exit(1);
	}
	if (parse(data, argv[1]) == 0)
	{
		ft_putstr_fd("Map parse failed\n", 1);
		broke(data->map);
		exit(1);
	}
	if (valid_map_format(data) == 0)
	{
		ft_putstr_fd("Invalid characters in map\n", 1);
		broke(data->map);
		exit(1);
	}
}

void	main_split_2(t_data *data)
{
	if (ccount(data) == 0 || pecount(data) == 0)
	{
		ft_putstr_fd("Invalid player / exit / collectible count\n", 1);
		broke(data->map);
		exit(1);
	}
	if (flood(data) == 0)
	{
		ft_putstr_fd("Invalid map, impossible path\n", 1);
		broke(data->map);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	if (argc != 2)
		return (0);
	main_split(&data, argv);
	main_split_2(&data);
	if (mlx(&data) == 0)
	{
		ft_putstr_fd("MLX initialisation failed\n", 1);
		broke(data.map);
		exit(1);
	}
	return (0);
}
