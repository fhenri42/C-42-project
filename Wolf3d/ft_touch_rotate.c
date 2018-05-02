/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:26:04 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/22 10:17:08 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	deplacement_camera(int keycode, t_data *v)
{
	double rp;

	rp = 0.25;
	if (keycode == 2 || keycode == 124)
	{
		v->old_dir_x = v->dir_x;
		v->dir_x = v->dir_x * cos(-rp) - v->dir_y * sin(-rp);
		v->dir_y = v->old_dir_x * sin(-rp) + v->dir_y * cos(-rp);
		v->old_plane_x = v->plane_x;
		v->plane_x = v->plane_x * cos(-rp) - v->plane_y * sin(-rp);
		v->plane_y = v->old_plane_x * sin(-rp) + v->plane_y * cos(-rp);
	}
	if (keycode == 0 || keycode == 123)
	{
		v->old_dir_x = v->dir_x;
		v->dir_x = v->dir_x * cos(rp) - v->dir_y * sin(rp);
		v->dir_y = v->old_dir_x * sin(rp) + v->dir_y * cos(rp);
		v->old_plane_x = v->plane_x;
		v->plane_x = v->plane_x * cos(rp) - v->plane_y * sin(rp);
		v->plane_y = v->old_plane_x * sin(rp) + v->plane_y * cos(rp);
	}
}

void	ft_victoire(t_data *v, int keycode)
{
	if (keycode == 91 && v->r_cou <= 7)
		v->r_cou++;
	if (keycode == 84 && v->r_cou > 1)
		v->r_cou--;
	if (v->grid[(int)v->pos_x][(int)v->pos_y] == 9)
		exit(0);
}

void	deplacement1(int keycode, t_data *v)
{
	double	ms;

	ms = 0.5;
	if (keycode == 13 || keycode == 126)
	{
		if (v->grid[(int)(v->pos_x + v->dir_x * ms)][(int)v->pos_y] == 0
				|| v->grid[(int)(v->pos_x + v->dir_x * ms)][(int)v->pos_y] == 9)
			v->pos_x += v->dir_x * ms;
		if (v->grid[(int)v->pos_x][(int)(v->pos_y + v->dir_y * ms)] == 0
				|| v->grid[(int)(v->pos_x + v->dir_x * ms)][(int)v->pos_y] == 9)
			v->pos_y += v->dir_y * ms;
	}
	if (keycode == 1 || keycode == 125)
	{
		if (v->grid[(int)(v->pos_x - v->dir_x * ms)][(int)v->pos_y] == 0)
			v->pos_x -= v->dir_x * ms;
		if (v->grid[(int)v->pos_x][(int)(v->pos_y - v->dir_y * ms)] == 0)
			v->pos_y -= v->dir_y * ms;
	}
}

int		touch_rotate(int keycode, t_data *v)
{
	mlx_destroy_image(v->mlx, v->img);
	mlx_clear_window(v->mlx, v->win);
	v->img = mlx_new_image(v->mlx, W, H);
	if (keycode == 18)
		map_generator(v);
	if (keycode == 78 && v->diff >= 1)
		v->diff--;
	if (keycode == 69)
		v->diff++;
	deplacement_camera(keycode, v);
	deplacement1(keycode, v);
	ft_victoire(v, keycode);
	map_gene(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	if (keycode == 53)
		if (keycode == 53)
			exit(0);
	return (0);
}
