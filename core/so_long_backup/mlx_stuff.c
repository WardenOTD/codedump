/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:15:04 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/02 17:46:35 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ptr_init(t_data *data)
{
	int	img_width;
	int	img_height;

	data->wall_ptr = mlx_new_image(data->mlx_ptr, data->map_width, data->map_height);
	data->floor_ptr = mlx_new_image(data->mlx_ptr, data->map_width, data->map_height);
	data->sprite_ptr = mlx_new_image(data->mlx_ptr, data->map_width, data->map_height);
	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall2x2.xpm", &img_width, &img_height);
	data->floor_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor2x2-2.xpm", &img_width, &img_height);
	data->sprite_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/sprite.xpm", &img_width, &img_height);
	data->col_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/collectible.xpm", &img_width, &img_height);
	data->exit_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit_off.xpm", &img_width, &img_height);
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

void	mlx_clean(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	mlx_destroy_image(data->mlx_ptr, data->floor_ptr);
	mlx_destroy_image(data->mlx_ptr, data->sprite_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	create_img_helper(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_ptr, x * 60, y * 60);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, x * 60, y * 60);
	else if (data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, x * 60, y * 60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, x * 60, y * 60);
	}
	else if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, x * 60, y * 60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->col_ptr, x * 60, y * 60);
	}
	else if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, x * 60, y * 60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_ptr, x * 60, y * 60);
	}
}

void	create_img(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			create_img_helper(data, x, y);
			x++;
		}
		y++;
	}
}

void	collection(t_data *data)
{
	int	img_width;
	int	img_height;

	if (data->map[data->sprite_y60 / 60][data->sprite_x60 / 60] == 'C')
	{
		data->ccount--;
		if (data->ccount == 0)
		{
			data->sprite_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/sprite_pu.xpm", &img_width, &img_height);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x60, data->sprite_y60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x60, data->sprite_y60);
	}
}

int	mlx(t_data *data)
{
	ccount(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	win_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width, data->map_height, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	ptr_init(data);
	create_img(data);
	mlx_key_hook(data->win_ptr, movement_admin, data);
	mlx_loop(data->mlx_ptr);
	mlx_clean(data);
	return (1);
}
