/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:15:04 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/03 17:18:11 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ptr_init(t_data *data)
{
	int	img_width;
	int	img_height;

	data->wall_ptr = mlx_new_image(data->mlx_ptr,
			data->map_width, data->map_height);
	data->floor_ptr = mlx_new_image(data->mlx_ptr,
			data->map_width, data->map_height);
	data->sprite_ptr = mlx_new_image(data->mlx_ptr,
			data->map_width, data->map_height);
	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall2x2.xpm", &img_width, &img_height);
	data->floor_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor2x2-2.xpm", &img_width, &img_height);
	data->sprite_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/sprite.xpm", &img_width, &img_height);
	data->col_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collectible.xpm", &img_width, &img_height);
	data->exit_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_off.xpm", &img_width, &img_height);
}

void	win_size(t_data *data)
{
	while (data->map[data->map_height] != NULL)
	{
		while (data->map[data->map_height][data->map_width] != '\n')
			data->map_width++;
		data->map_height++;
	}
	data->map_height *= 60;
	data->map_width *= 60;
}

int	mlx_clean(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	mlx_destroy_image(data->mlx_ptr, data->floor_ptr);
	mlx_destroy_image(data->mlx_ptr, data->sprite_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	broke(data->map);
	exit(0);
	return (0);
}

int	mlx(t_data *data)
{
	ccount(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (0);
	}
	win_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map_width, data->map_height, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	ptr_init(data);
	create_img(data);
	mlx_key_hook(data->win_ptr, movement_admin, data);
	mlx_hook(data->win_ptr, 17, 0, mlx_clean, data);
	mlx_loop(data->mlx_ptr);
	mlx_clean(data);
	return (1);
}
