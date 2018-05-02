/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:57 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/22 12:09:38 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_where_to_draw(t_data *v, int x)
{
	int line_height;
	int draw_start;
	int draw_end;

	line_height = (int)(H / v->wall_dist);
	draw_start = -line_height / 2 + H / v->r_cou;
	draw_end = line_height / 2 + H / v->r_cou;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= H)
		draw_end = H - 1;
	draw_2_0(x, v, draw_end, draw_start);
}

void	ft_wall_touch(t_data *v, int x)
{
	while (v->hit != 1)
	{
		if (v->side_dist_x < v->side_dist_y)
		{
			v->side_dist_x += v->delta_dist_x;
			v->map_x += v->step_x;
			v->side = 0;
			draw_the_sky(x, v, H / v->r_cou, 1);
			draw_the_floar(x, v, H, H / v->r_cou);
		}
		else
		{
			v->side_dist_y += v->delta_dist_y;
			v->map_y += v->step_y;
			v->side = 1;
			draw_the_sky(x, v, H / v->r_cou, 1);
			draw_the_floar(x, v, H, H / v->r_cou);
		}
		if (v->grid[v->map_x][v->map_y] != 0
				&& v->grid[v->map_x][v->map_y] != 5)
			v->hit = 1;
	}
}

void	ft_retrace_suite(t_data *v, int x)
{
	ft_wall_touch(v, x);
	v->delta_dist_x = sqrt(1 + (v->ray_dir_y * v->ray_dir_y)
						/ (v->ray_dir_x * v->ray_dir_x));
	v->delta_dist_y = sqrt(1 + (v->ray_dir_x * v->ray_dir_x)
						/ (v->ray_dir_y * v->ray_dir_y));
	if (v->side == 0)
		v->wall_dist = (v->map_x - v->pos_x +
				(1 - v->step_x) / 2) / v->ray_dir_x;
	else
		v->wall_dist = (v->map_y - v->pos_y +
				(1 - v->step_y) / 2) / v->ray_dir_y;
	ft_where_to_draw(v, x);
}

void	ft_retrace(t_data *v, int x)
{
	if (v->ray_dir_x < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (v->pos_x - v->map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->map_x + 1.0 - v->pos_x) * v->delta_dist_x;
	}
	if (v->ray_dir_y < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (v->pos_y - v->map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->map_y + 1.0 - v->pos_y) * v->delta_dist_y;
	}
	ft_retrace_suite(v, x);
}

void	map_gene(t_data *v)
{
	int x;

	x = 0;
	while (x < W)
	{
		v->camera_x = 2 * x / (double)W - 1;
		v->ray_dir_x = v->dir_x + v->plane_x * v->camera_x;
		v->ray_dir_y = v->dir_y + v->plane_y * v->camera_x;
		v->delta_dist_x = sqrt(1 + (v->ray_dir_y * v->ray_dir_y)
						/ (v->ray_dir_x * v->ray_dir_x));
		v->delta_dist_y = sqrt(1 + (v->ray_dir_x * v->ray_dir_x)
						/ (v->ray_dir_y * v->ray_dir_y));
		v->map_x = (int)v->pos_x;
		v->map_y = (int)v->pos_y;
		v->hit = 0;
		ft_retrace(v, x);
		x++;
	}
}
