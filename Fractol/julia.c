/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:51:40 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/11 14:54:33 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_draw2(t_data *val)
{
	val->olde_re = val->new_re;
	val->olde_im = val->new_im;
	val->new_re = val->olde_re * val->olde_re
		- val->olde_im * val->olde_im + val->cre;
	val->new_im = 2 * val->olde_re * val->olde_im + val->cim;
}

void	ft_remise_zero2(t_data *val)
{
	val->olde_re = val->new_re;
	val->olde_im = val->new_im;
}

void	ft_suite42(t_data *val, int x, int y, int i)
{
	val->color = (i % 256 * (i < val->iteration));
	if (val->colo == 0)
		pixel_to_image(mlx_get_color_value(val->mlx, 0x00FFF999 * val->color),
				val, x, y);
	if (val->colo == 1)
		pixel_to_image(mlx_get_color_value(val->mlx, 0x00CC33F * val->color),
				val, x, y);
	if (val->colo == 2)
		pixel_to_image(mlx_get_color_value(val->mlx, 0x006600CC * val->color),
				val, x, y);
	if (val->colo == 3)
		pixel_to_image(mlx_get_color_value(val->mlx, 0x0066CCFF * val->color),
				val, x, y);
}

void	ft_julia(t_data *val)
{
	int x;
	int y;
	int i;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 650)
		{
			val->new_re = (double)x / (1000 / (val->x2 - val->x1)) + val->x1;
			val->new_im = (double)y / (650 / (val->y2 - val->y1)) + val->y1;
			ft_remise_zero2(val);
			i = -1;
			while (i++ < val->iteration &&
					(val->new_re * val->new_re + val->new_im * val->new_im) < 4)
				ft_draw2(val);
			ft_suite42(val, x, y, i);
			y++;
		}
		x++;
	}
}
