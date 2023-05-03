/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:20:41 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/03 16:32:47 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img_helper_helper(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->floor_ptr, x * 60, y * 60);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->col_ptr, x * 60, y * 60);
	}
	if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->floor_ptr, x * 60, y * 60);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_ptr, x * 60, y * 60);
	}
}

void	create_img_helper(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall_ptr, x * 60, y * 60);
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->floor_ptr, x * 60, y * 60);
	if (data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->floor_ptr, x * 60, y * 60);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->sprite_ptr, x * 60, y * 60);
	}
	create_img_helper_helper(data, x, y);
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
