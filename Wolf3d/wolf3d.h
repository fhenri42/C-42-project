/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:20:07 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/22 12:33:36 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <ft_color.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# define BUF_SIZE 10
# define W 1200
# define H 800

typedef struct		s_data
{

	double			plane_y;
	double			plane_x;
	double			pos_x;
	double			pos_y;
	double			dir_y;
	double			dir_x;
	double			old_dir_x;
	double			old_plane_x;
	double			side_dist_x;
	double			side_dist_y;
	double			wall_dist;
	double			ray_dir_x;
	double			ray_dir_y;
	double			camera_x;
	double			delta_dist_x;
	double			delta_dist_y;
	int				r_cou;
	int				forbid;
	int				alea;
	unsigned int	diff;
	int				fin;
	int				b;
	int				y;
	int				x;
	int				conteur;
	int				**grid;
	void			*mlx;
	void			*win;
	void			*img;
	int				r;
	int				g;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
}					t_data;
int					expose_hook(int x, int y, t_data *val);
void				ft_suite(char *str, t_data *val);
int					touch_rotate(int keycode, t_data *val);
void				tab_pos(t_data *val);
void				map_gene(t_data *val);
void				ft_verife(char *buf);
void				tab_pos(t_data *val);
void				pixel_to_image(unsigned long color,
					t_data *val, int x, int y);
void				ft_verife_valid(t_data *val);
int					get_color(char *data, int x, int y);
void				map_generator(t_data *val);
void				draw_2_0(int x, t_data *val,
					double draw_end, double draw_start);
void				draw_the_sky(int x, t_data *val,
					int draw_end, int draw_start);
void				draw_the_floar(int x, t_data *val,
					int draw_end, int draw_start);

#endif
