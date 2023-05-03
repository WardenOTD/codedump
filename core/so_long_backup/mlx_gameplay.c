/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_gameplay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:42 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/03 16:34:25 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collection(t_data *data)
{
	int	img_width;
	int	img_height;

	if (data->map[data->sprite_y60 / 60][data->sprite_x60 / 60] == 'C')
	{
		data->ccount--;
		data->map[data->sprite_y60 / 60][data->sprite_x60 / 60] = '0';
		if (data->ccount == 0)
		{
			data->sprite_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
					"./textures/sprite_pu.xpm", &img_width, &img_height);
			data->exit_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
					"./textures/exit.xpm", &img_width, &img_height);
		}
		exit_replace(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_ptr, data->sprite_x60, data->sprite_y60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_ptr, data->sprite_x60, data->sprite_y60);
	}
}

void	exit_replace(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != 0)
		{
			if (data->map[y][x] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->floor_ptr, x * 60, y * 60);
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->exit_ptr, x * 60, y * 60);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	exit_reach(t_data *data)
{
	if (data->map[data->sprite_y60 / 60][data->sprite_x60 / 60] == 'E')
		mlx_clean(data);
}
