/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_movement_admin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:45:46 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/02 17:49:46 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_admin(int keycode, t_data *data)
{
	static int	movement = 0;

	if (keycode == 53)
		mlx_clean(data);
	if (keycode == 13)
		w(data);
	if (keycode == 0)
		a(data);
	if (keycode == 1)
		s(data);
	if (keycode == 2)
		d(data);
	collection(data);
	movement++;
	ft_putnbr_fd(movement, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

void	w(t_data *data)
{
	if (data->map[(data->sprite_y60 / 60) - 1][data->sprite_x60 / 60] != '1')
	{
		if (data->map[(data->sprite_y60 / 60) - 1][data->sprite_x60 / 60] == 'E' && data->ccount != 0)
			return ;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x60, data->sprite_y60 - 60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x60, data->sprite_y60);
		data->sprite_y60 -= 60;
	}
}

void	a(t_data *data)
{
	if (data->map[data->sprite_y60 / 60][(data->sprite_x60 / 60) - 1] != '1')
	{
		if (data->map[data->sprite_y60 / 60][(data->sprite_x60 / 60) - 1] == 'E' && data->ccount != 0)
			return ;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x60 - 60, data->sprite_y60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x60, data->sprite_y60);
		data->sprite_x60 -= 60;
	}
}

void	s(t_data *data)
{
	if (data->map[(data->sprite_y60 / 60) + 1][data->sprite_x60 / 60] != '1')
	{
		if (data->map[(data->sprite_y60 / 60) + 1][data->sprite_x60 / 60] == 'E' && data->ccount != 0)
			return ;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x60, data->sprite_y60 + 60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x60, data->sprite_y60);
		data->sprite_y60 += 60;
	}
}

void	d(t_data *data)
{
	if (data->map[data->sprite_y60 / 60][(data->sprite_x60 / 60) + 1] != '1')
	{
		if (data->map[data->sprite_y60 / 60][(data->sprite_x60 / 60) + 1] == 'E' && data->ccount != 0)
			return ;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x60 + 60, data->sprite_y60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x60, data->sprite_y60);
		data->sprite_x60 += 60;
	}
}

//           COLLECTION DONE
//           UNDONE -------- EXIT, EXIT TEXTURE, NORM, LEAKS, MAKEFILE
