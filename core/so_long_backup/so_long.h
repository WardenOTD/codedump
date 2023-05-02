/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:26:45 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/02 17:46:24 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# endif

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
	int		sprite_x60;
	int		sprite_y60;
	char	**map;
	int		mapsize;
	int		map_width;
	int		map_height;
	int		ccount;
	int		exit;
}				t_data;

//---MAIN---
int			main(int argc, char **argv);

void		init(t_data *data);

void		broke(t_data *data);


//---FLOODFILL ALGO---
int			flood(t_data *data);

int			fill(int x, int y, char **tmp, t_data *data);

char		**dupe(t_data *data);

void		locatep(t_data *data);


//---MAP VALIDATION---
int			pecount(t_data *data);

int			ccount(t_data *data);

int			mapsize(t_data *data, char *argv);

int			parse(t_data *data, char *argv);

int			validity(t_data *data);

int			validity_helper(t_data *data, int i);


//---MLX FUNCTIONS---
int			mlx(t_data *data);

void		mlx_clean(t_data *data);

void		win_size(t_data *data);

void		ptr_init(t_data *data);

void		create_img(t_data *data);

void		create_img_helper(t_data *data, int x, int y);


//---MLX MOVEMENT---
int			movement_admin(int keycode, t_data *data);

void		w(t_data *data);

void		a(t_data *data);

void		s(t_data *data);

void		d(t_data *data);

void		collection(t_data *data);


//---PUT TO TERMINAL FUNCS---
void		ft_putnbr_fd(int n, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putchar_fd(char c, int fd);
