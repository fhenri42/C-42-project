/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 19:16:09 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/11 14:55:10 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_draw1(t_data *val)
{
	val->olde_re = fabs(val->new_re);
	val->olde_im = fabs(val->new_im);
	val->new_re = val->olde_re * val->olde_re
		- val->olde_im * val->olde_im + val->pr;
	val->new_im = 2 * val->olde_re * val->olde_im + val->pi;
}

void	ft_remise_zero1(t_data *val)
{
	val->new_re = 0;
	val->new_im = 0;
	val->olde_re = 0;
	val->olde_im = 0;
}

void	ft_suite41(t_data *val, int x, int y, int i)
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

void	ft_ship(t_data *val)
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
			val->pr = (double)x / (1000 / (val->x2 - val->x1)) + val->x1;
			val->pi = (double)y / (650 / (val->y2 - val->y1)) + val->y1;
			ft_remise_zero1(val);
			i = -1;
			while (i++ < val->iteration &&
					(val->new_re * val->new_re + val->new_im * val->new_im) < 4)
				ft_draw1(val);
			ft_suite41(val, x, y, i);
			y++;
		}
		x++;
	}
}
