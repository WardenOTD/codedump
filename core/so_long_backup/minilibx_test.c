#include <stdlib.h>
#include <mlx.h>
#include "get_next_line.h"
#include <stdio.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1
// all test code, just tryna figure out how all these works before attempting the project

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
}				t_data;

int	move(int	keycode, t_data *data)
{
	int			img_width;
	int			img_height;
	static int	count = 1;

	if (keycode == 13)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x, data->sprite_y - 60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x, data->sprite_y);
		data->sprite_y -= 60;
	}
	else if (keycode == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x - 60, data->sprite_y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x, data->sprite_y);
		data->sprite_x -= 60;
	}
	if (keycode == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x, data->sprite_y + 60);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x, data->sprite_y);
		data->sprite_y += 60;
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_ptr, data->sprite_x + 60, data->sprite_y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_ptr, data->sprite_x, data->sprite_y);
		data->sprite_x += 60;
	}
	printf("%d\n", count);
	count++;
	return (0);
}

int main(void)
{
	t_data	data;
	int		img_width;
	int		img_height;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.wall_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.floor_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.sprite_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.wall_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./textures/wall2x2.xpm", &img_width, &img_height);
	data.floor_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./textures/floor2x2-2.xpm", &img_width, &img_height);
	data.sprite_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./textures/sprite.xpm", &img_width, &img_height);
	data.col_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./textures/collectible.xpm", &img_width, &img_height);
	data.exit_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./textures/exit_off.xpm", &img_width, &img_height);
	for (int j = 0; j < 600; j += 60)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall_ptr, j, 0);
	for (int j = 0; j < 600; j += 60)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall_ptr, 0, j);
	for (int j = 0; j < 600; j += 60)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall_ptr, 540, j);
	for (int j = 0; j < 600; j += 60)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall_ptr, j, 540);
	for (int k = 60; k < 540; k += 60)
		for (int i = 60; i < 540; i += 60)
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.floor_ptr, i, k);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprite_ptr, 120, 120);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.exit_ptr, 180, 480);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.col_ptr, 360, 60);
	data.sprite_x = 120;
	data.sprite_y = 120;
	mlx_key_hook(data.win_ptr, move, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.wall_ptr);
	mlx_destroy_image(data.mlx_ptr, data.floor_ptr);
	mlx_destroy_image(data.mlx_ptr, data.sprite_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}

//run
//gcc minilibx_test.c get_next_line.c get_next_line_utils.c -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3 -o so_long && rm -rf so_long.dSYM && ./so_long

