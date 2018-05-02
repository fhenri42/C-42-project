/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:07:52 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/22 11:59:41 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_the_floar(int x, t_data *val, int draw_end, int draw_start)
{
	while (draw_start < draw_end)
	{
		pixel_to_image(0x00FFCC00, val, x, draw_start);
		draw_start++;
	}
}

void	draw_the_sky(int x, t_data *val, int draw_end, int draw_start)
{
	while (draw_start < draw_end)
	{
		pixel_to_image(0x000000FF, val, x, draw_start);
		draw_start++;
	}
}

void	draw_2_0(int x, t_data *val, double draw_end, double draw_start)
{
	while (draw_start < draw_end)
	{
		if (val->grid[val->map_x][val->map_y] == 9)
		{
			if (val->side == 1)
				pixel_to_image(0x00000000, val, x, draw_start);
			else
				pixel_to_image(0x00FFFFFF, val, x, draw_start);
		}
		else
		{
			if (val->side == 1)
				pixel_to_image(0x006633FF, val, x, draw_start);
			else
				pixel_to_image(0x00990000, val, x, draw_start);
		}
		draw_start++;
	}
}
